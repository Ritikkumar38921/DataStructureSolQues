#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int minimum(int a,int b,int c){
  
  if(a < b){
    return (a < c)?a:c; 
  }else{
    return (b < c)?b:c;
  }
}
int editdistance(string s1,string s2,int m,int n){
  if(m == 0){
    return n;
  }
  if(n == 0){
    return m;
  }
  if(s1[m-1] == s2[n-1]){
    return editdistance(s1,s2,m-1,n-1);
  }else{
    return 1 + (minimum(editdistance(s1,s2,m,n-1),editdistance(s1,s2,m-1,n-1),editdistance(s1,s2,m-1,n)));
  }



}
int main(){
  string s1 = "sunday";
  string s2 = "saturday";
  int ans = editdistance(s1,s2,s1.size(),s2.size());
  cout << ans;
  return 0;
}
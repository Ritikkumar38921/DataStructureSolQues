#include<bits/stdc++.h>
using namespace std;

int getWays(int amt,int m,int *arr,int i){
  if(i == m)
   return 0;

   if( amt == 0){
    return 1;
   }
  int ans = 0;
   if(amt >= arr[i])
   {  
       int a = getWays(amt - arr[i],m,arr,i);
       ans += a;
   }
   int b = getWays(amt,m,arr,i+1);
   return (ans + b);
}

int main(){
    int amt = 10;
    int m = 4;
    int *arr = new int[m];
    for( int i=0;i<m;i++)
    cin >> arr[i];
     int Ans = getWays(amt,m,arr,0);
     cout << " answer is "<<Ans;
    return 0;
}
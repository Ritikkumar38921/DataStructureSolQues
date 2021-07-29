#include<iostream>
#include<limits.h>
using namespace std;

int maximumValue(int n,int *length,int *rate){
 int dp[n+1] = {0};

 for(int i=1;i<n+1;i++){
   int ans = rate[i-1];
   if( i - 1 == 0){
     dp[i] = ans;
     continue;
   }
   for(int j = i-1;j>=0 && (j >= (i&1 == 1)?(i/2)-1:(i/2));j--){
     ans = max(ans,dp[j] + dp[i - j]);   
   }
   dp[i] = ans;
 }
 
 return dp[n];
}
int main(){
  int n;
  cin >> n;
  int *len = new int[n];
  int *price = new int[n];
  for(int i = 0;i<n;i++){
    cin >> len[i] >> price[i];
  }
  int ans = maximumValue(n,len,price);
  cout << "answer is "<<ans;
  return 0;
}
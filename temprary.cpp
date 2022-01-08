#include<bits/stdc++.h>
using namespace std;


// find the fibbonacci no.
int fib(int n,int* dp){
	if(n == 0 || n == 1){
		return n;
	}
	if(dp[n] != -1){
		return dp[n];
	}
	dp[n] = fib(n-1,dp) + fib(n-2,dp);
	return dp[n];
}

int fibbonacci(int* dp,int n){
	if(n == 0 || n == 1){
		return n;
	}
	for(int i = 2;i<=n;i++){
		dp[i] = dp[i-1] + dp[i-2];
	}
	return dp[n];
}

int main(){
	int n;
	cin >> n;
	int *dp = new int[n+1];
	for(int i = 0; i<=n ; i++){
		dp[i] = -1;
	}
	dp[0] = 0;
	dp[1] = 1;
	int ans = fibbonacci(dp,n);
	cout << " ans : "<< ans << endl;
	for(int i=0;i<=n;i++){
		cout << dp[i] << " ";
	}

	return 0;
}

















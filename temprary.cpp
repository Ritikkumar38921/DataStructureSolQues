#include<bits/stdc++.h>
using namespace std;


// finding the longest increasing sequences....

int longestIncreasingSubsequences(int *arr,int s,int n,int prevIndex,int currLen){
	if(s == n){
		return currLen;
	}

	if(prevIndex == -1){
		int res1 = longestIncreasingSubsequences(arr,s+1,n,s,currLen+1);
		int res2 = longestIncreasingSubsequences(arr,s+1,n,prevIndex,currLen);
		if(res1 > res2){
			return res1;
		}
		return res2;
	}
	else{
		int res1,res2;
		res1 = -1;
		res2 = 0;
		if(arr[s] > arr[prevIndex]){
		 res1 = longestIncreasingSubsequences(arr,s+1,n,s,currLen+1);
		}
		 res2 = longestIncreasingSubsequences(arr,s+1,n,prevIndex,currLen);
		if(res1 != -1){
			if(res1 > res2){
			return res1;
		}
		 	return res2;
		}else{
			return res2;
		}
	}
}

int lcs(int *arr,int n){
	int *dp = new int[n];
	dp[0] = 1;
	for(int i = 1 ; i < n ; i++){
		int max = INT_MIN;
		for(int j = i-1; j >= 0 ; j--){
			if(arr[i] > arr[j]){
				max = (max < dp[j])?dp[j]:max;
			}
		}
		dp[i] = max + 1;
	}

	for(int i = 0;i<n;i++){
		cout << dp[i] << " ";
	}

	return dp[n - 1];
}

int main(){
	int n;
	cin >> n;
	int *arr = new int[n];
	for(int i = 0;i<n;i++){
		cin >> arr[i];
	}

	int ans = lcs(arr,n);
	cout << " \nlongest increasing SubSequence : "<< ans << endl;
 	return 0;
}







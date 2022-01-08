#include<bits/stdc++.h>
using namespace std;

// using memoization 
int MinimumJumpsRequired(int *arr,int n,int index,int *dp){
	if(index >= n-1){
		return 0;
	}

	if(dp[index] != -1){
		return dp[index];
	}

	int min = INT_MAX;
	for(int i = 1;i <= arr[index];i++){
		int temp =  1 + MinimumJumpsRequired(arr,n,index+i,dp);
		if(min > temp){
			min = temp;
		}
	}

	if(min == INT_MAX){
		return INT_MAX;
	}
	cout << index << " -> "<<min<<endl;
	dp[index] = min;
	return dp[index];
}

// bottom up approach
int MinJumpProblem(int arr[],int n,int index){
	if(n == 0)
	{
		return INT_MAX;
	}

	if(n == 1){
		return 0;
	}

	int dp[n];
	for(int i = 0 ; i < n ;i++){
		dp[i] = INT_MAX;
	}
	dp[n-1] = 0;
	cout << (n - 1) << " -> " << dp[n - 1]<<endl;
	for(int i = n-2 ; i >= 0 ; i--){
		int min = INT_MAX;
		for(int jump = 1 ; (jump <= n - 1) && (jump <= arr[i]) ; jump++){
			if(min > dp[i+jump]){
				min = dp[i + jump];
			}
		}
		if(min == INT_MAX){
			return INT_MAX;
		}
		dp[i] = min + 1;
		cout << i << " -> " << dp[i]<<endl;
	} 

	for(int i=0;i<n;i++){
		cout << dp[i] << " ";
	}

	return dp[0];
}

int greedyApproach(int arr[],int n,int index){
	// maximum jump I can make from the current index;
	int prev = 0;
	// how many jumps I take to reach at the final index
	int jump = 0;
	// maximum range 
	int maxRange = 0;

	for(int i=0;i<n;i++){
		if(i > prev){
			jump++;
			prev = maxRange;
		}
		maxRange = (maxRange > i + arr[i])?maxRange:(i + arr[i]);
	}
	return jump;

}
int main(){
	int n;
	cin >> n;
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	int ans = greedyApproach(arr,n,0);
	cout << "\n minimum jumps required to reach at the end position : "<<ans;
	
	return 0;
}





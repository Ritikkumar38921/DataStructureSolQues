#include<bits/stdc++.h>
using namespace std;
// coin changing problem...

int coinChangeProblem(int **dp,int* arr,int n,int val){
	if(val == 0){
		return 1;
	}
	if(val < 0 || n == 0){
		return 0;
	}
	if(dp[n-1][val] > 0){
		return dp[n-1][val];
	}
	dp[n-1][val] = coinChangeProblem(dp,arr,n,val-arr[n-1]) + coinChangeProblem(dp,arr,n-1,val);
	return dp[n-1][val];
}

int coinChangeProblem(int *arr,int n,int val){
	if(n == 0 || val == 0){
		return 0;
	}

	int dp[n][val+1];
	for(int i = 0;i<n;i++){
		for(int j=0;j<=val;j++){
			dp[i][j] = 0;
		}
	}
	for(int i = 0 ; i < n ; i++){

		cout << i << " - > "<<endl;
		for(int j = 0 ; j <= val; j++){
			if(i == 0 && j == 0){
				dp[i][j] = 1;
			}else if(i == 0){
				if(arr[i] <= j)
					dp[i][j] = dp[i][j - arr[i]];
			}else if(j == 0){
				dp[i][j] = dp[i-1][j];
			}else{
				if(arr[i] > j){
					dp[i][j] = dp[i-1][j]; 
				}else{
					dp[i][j] = dp[i-1][j] + dp[i][j - arr[i]];
				}
			}
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	for(int i = 0; i < n ; i++){
		for(int j=0;j<=val;j++){
			cout << dp[i][j]<< " ";
		}
		cout << endl;
	}
	return dp[n-1][val];
}

int bestAppraoach(int *coins,int n,int val){
	if(n == 0 || val == 0){
		return 0;
	}
	int *dp = new int[val + 1];
	for(int  i = 0;i<=val;i++){
		dp[i] = 0;
	}
	dp[0] = 1;
	for(int i = 0 ; i<n;i++){
		for(int j=coins[i];j <= val ; j++){
			dp[j] += dp[j - coins[i]];
		}
	}
	return dp[val];
}

int main(){
	int n,val;
	cin >> n >> val;
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	int **dp1 = new int*[n];
	for(int i = 0;i<n;i++){
		dp1[i] = new int[val+1];
	}
	for(int i = 0; i < n ; i++){
		for(int j=0;j<=val;j++){
			dp1[i][j] = 0;
		}
	}
	int ans = bestAppraoach(arr,n,val);
	int Ans = coinChangeProblem(dp1,arr,n,val);
	cout<<ans<<" " <<Ans<<endl;
	return 0;
}




















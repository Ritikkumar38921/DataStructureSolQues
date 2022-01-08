#include<bits/stdc++.h>
using namespace std;

// knapsack problem ...


int recursion(int values[],int weight[],int knapSack,int n,int currProfit){
	if(n == 0 || knapSack == 0){
		return currProfit;
	}else if(knapSack < 0){
		return -1;
	}

	if(weight[n-1] > knapSack){
		return recursion(values,weight,knapSack, n-1 ,currProfit);
	}
	else{
	int ans = recursion(values,weight,knapSack - weight[n-1],n-1,currProfit+values[n-1]);
	int ans1 = recursion(values,weight,knapSack,n-1,currProfit);
	return (ans > ans1)?ans:ans1;

	}
}

int bottomUp(int values[],int weight[],int knapsack,int n,int profit){

	int dp[n+1][knapsack + 1];
	for(int i = 0;i<=n;i++){
		for(int j = 0;j<=knapsack;j++){
			dp[i][j] = 0;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for(int j = 1;j<= knapsack;j++){
			if(weight[i-1] <= j){
				dp[i][j] = (dp[i-1][j] < (values[i]+dp[i-1][j - weight[i-1]]))?values[i-1]+dp[i-1][j - weight[i-1]]:dp[i-1][j];
			}else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	
	for(int i = 0;i<=n;i++){
		for(int j = 0 ; j <= knapsack ; j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	return dp[n][knapsack];
}

int recursionMemoization(int **dp,int values[],int weight[],int knapSack,int n,int currProfit){
	if(n == 0 || knapSack == 0){
		return currProfit;
	}else if(knapSack < 0){
		return -1;
	}
	if(dp[n-1][knapSack] != 0){
		return dp[n - 1][knapSack];
	}

	if(weight[n-1] > knapSack){
		dp[n-1][knapSack] = recursion(values,weight,knapSack, n-1 ,currProfit);
	}else{
		int ans = recursionMemoization(dp,values,weight,knapSack - weight[n-1],n-1,currProfit+values[n-1]);
		int ans1 = recursionMemoization(dp,values,weight,knapSack,n-1,currProfit);
		dp[n-1][knapSack]  = (ans > ans1)?ans:ans1;
	}
	return dp[n-1][knapSack];
}

int main(){
	int values[] = {60,100,150};
	int weight[] = {15,30,45};
	int knapSack = 50;
	int **dp = new int*[3];
	for(int i=0;i<3;i++){
		dp[i] = new int[51];
	}
	for(int i = 0;i<3;i++){
		for(int j = 0 ; j <= 50 ; j++){
			dp[i][j] = 0;
		}
	}
	int ans = bottomUp(values,weight,knapSack,3,0);
	if(ans != -1){
		cout << "maximum profit we can obtain : "<< ans << endl;
	}
	return 0;
}








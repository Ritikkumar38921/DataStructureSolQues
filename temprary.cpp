
#include<iostream>
#include<limits.h>
using namespace std;

/// travelling salesman problem .
int count = 0;
int mat[4][4] = {
	{0,20,42,25},
	{20,0,30,34},
	{42,30,0,10},
	{25,34,10,0}
};



int min(int a,int b){
	return (a > b)?b:a;
}

int tsp(int dp[4][16],int mask,int src,int last,int init){
	count++;
	if(mask == (1 << 4)-1){
		return mat[src][init];
	}
	if(dp[src][mask] != 0){
		return dp[src][mask];
	}

	int ans = INT_MAX;
	for(int city=0;city<4;city++){
		if((mask & (1 << city)) == 0){
			 ans = min(ans ,tsp(dp,mask|(1 << city),city,last,init)) + mat[src][city];
		}
	}
	dp[src][mask] = ans;

	return ans;
}

int main(){
	int src;
	cin >> src;
	int allVisitedMask = 0;
	int temp = 1;
	int prev = temp;
	
	int dp[4][16];
	for(int i=0;i<4;i++){
		for(int j = 0;j<16;j++){
			dp[i][j] = 0;
		}
	}	
	int ans = tsp(dp,src,src,allVisitedMask,src);
	cout << " minimum answer to reach all the cities are : "<<ans<<endl;
	cout << " count : "<< count<<endl;

	
	return 0;
}













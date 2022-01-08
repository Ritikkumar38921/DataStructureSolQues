#include<bits/stdc++.h>
using namespace std;

// findin minimum square that is needed to make a perticular number.

class Global{
	public:
		int minimumSquare(int x){
			if(x == 0 || x == 1 || x == 2 || x == 3){
			return x;
		}
		int min = INT_MAX;
		for(int i = 1; i <= sqrt(x);i++){
			int temp =  minimumSquare(x-(i*i));
			if(min > temp){
				min = temp;
				}
			}
			return (min + 1);
		}

		int minimumSquare(int x,int *dp){
			if(x == 0 || x == 1 || x == 2 || x == 3){
				return x;
			}
			if(dp[x] != -1){
				return dp[x];
			}
			int min = INT_MAX;
			for(int i = 1;i<=sqrt(x);i++){
				int smallAns = minimumSquare(x - (i * i),dp);
				if(smallAns < min){
					min = smallAns;
				}
			}
			dp[x] = min + 1;
			return dp[x];
		}
};

int minimum(int *dp,int x){
	if(x == 0 || x == 1 || x == 2 || x == 3){
		return x;
	}
	for(int i = 4;i<=x;i++){
		int min = INT_MAX;
		int index = -1;
		for(int j = 1;j<=sqrt(i);j++){
			if(min > (dp[i - (j*j)])){
				min = dp[i - (j*j)];
				 index = i - (j*j);
			}
		}
		dp[i] = min + 1;
		cout << i << " " << index <<  " + " << dp[i]<<endl;
	}
	return dp[x];
}

int main(){
	Global* obj = new Global();
	int x;
	cin >> x;
	int *dp = new int[x+1];
	for(int i = 0;i<=x;i++){
		dp[i] = -1;
	}
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	int ans = minimum(dp,x);
	cout << " ans : " << ans << endl;

	for(int i=0;i<=x;i++){
		cout << dp[i] << " ";
	}
	return 0;
}


















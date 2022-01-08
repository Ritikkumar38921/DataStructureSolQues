#include<bits/stdc++.h>
using namespace std;







void naiveApproach(string text,string pattern){
	int len = text.size();
	int index = 0;
	int n = pattern.size();
	for(int i = 0 ; i < (len - n) ; i++){
		for(int j = i; j < (i+n) ; j++){
			if(text[j] == pattern[index]){
				index++;
			}else{
				break;
			}
		}

		if(index == n){
			cout << " pattern found at index : "<<(i+n - index) << endl;
		}

		index = 0;
	}
}


void RabinKarp(string text,string pattern){
	int arr[26];
	for(int i=0;i<26;i++){
		arr[i] = i+1;
	}
	int n1 = pattern.size();
	int n = text.size();
	int prime = 13;
	int multiplier = 1;
	int ans = 0; 
	int hash = 0;
	for(int i = 0;i<n1;i++){
		ans += arr[int(pattern[i]) - 97];
		hash += arr[int(text[i]) - 97];
		if(i != n1-1){
			ans = ans * 10;
			hash = hash * 10;
		}
		ans = ans % prime;
		hash = hash % prime;
	}

	for(int i = 0;i<(n - n1);i++){
		if(i == 0){
			if(hash == ans){
				check();
			}
		}else{
			hash = hash - arr[i - 1] + arr[]
		}
	}



}
int main(){
	string text="abababacaba";
	string pattern = "ababaca";

	// naiveApproach(text,pattern);
	RabinKarp(text,pattern);
	return 0;
}
















// longest increasing subsequences with patience sorting technique

// struct node{
// 	node* link;
// 	node* prev;
// 	stack<int> st;
// 	node(){
// 		link = NULL;
// 		prev = NULL;
// 	}
// };

// void printFunc(node* root){
// 	int i = 0;
// 	node* t = root;
// 	while(t != NULL){
// 		cout << i << " -> \n ";
// 		while(t->st.size() > 0){
// 			cout << t->st.top() << " ";
// 			t->st.pop();
// 		}
// 		cout << endl;
// 		i++;
// 		t = t->link;
// 	}
// }
// int  patienceSort(int* arr,int n){
// 	if(n == 0 || n == 1){
// 		return n;
// 	}
// 	struct node* root;
// 	root = NULL;
// 	for(int i=0;i<n;i++){
// 		if(root == NULL){
// 			root = new node();
// 			root->st.push(arr[i]);
// 			root->prev = root;
// 		}else{
// 			node* temp = root;
// 			node* prev = NULL;
// 			while(temp != NULL){
// 				if(temp->st.top() > arr[i]){
// 					temp->st.push(arr[i]);
// 					if(prev != NULL)
// 					 	temp->prev = prev;
// 					else
// 						temp->prev = root;
// 					break;
// 				}else{
// 					prev = temp;
// 					temp = temp->link;	
// 				}
// 			}
// 			if(temp == NULL){
// 			    node* newAddress = new node();
// 				newAddress->st.push(arr[i]);
// 				prev->link = newAddress;
// 				newAddress->prev = prev;
// 			}	
// 		}
// 	}
// 	int count = 0;
// 	while(root != NULL){
// 		cout << root->st.top() << " ";
// 		count++;
// 		root = root->link;
// 	}
// 	return count;
// }




// int LIS(int *arr,int n){
//    return patienceSort(arr,n);
// }

// int main(){
// 	int n;
// 	cin >> n;
// 	int* arr = new int[n];
// 	for(int i=0;i<n;i++){
// 		cin >> arr[i];
// 	}
// 	int ans = LIS(arr,n);
// 	cout << " \nlongest increasing subSequence is "<< ans << endl;
// 	return 0;
// }




 // patience sort
// struct node{
// 	node* link;
// 	node* prev;
// 	stack<int> st;
// 	node(){
// 		link = NULL;
// 		prev = NULL;
// 	}
// };

// void printFunc(node* root){
// 	int i = 0;
// 	node* t = root;
// 	while(t != NULL){
// 		cout << i << " -> \n ";
// 		while(t->st.size() > 0){
// 			cout << t->st.top() << " ";
// 			t->st.pop();
// 		}
// 		cout << endl;
// 		i++;
// 		t = t->link;
// 	}
// }
// void patienceSort(int* arr,int n){
// 	if(n == 0 || n == 1){
// 		return;
// 	}else if(n == 2){
// 		if(arr[0] > arr[1]){
// 			int temp = arr[0];
// 			arr[0] = arr[1];
// 			arr[1] = temp;
// 		}
// 		return;
// 	}
// 	struct node* root;
// 	root = NULL;
// 	for(int i=0;i<n;i++){
// 		if(root == NULL){
// 			root = new node();
// 			root->st.push(arr[i]);
// 			root->prev = root;
// 		}else{
// 			node* temp = root;
// 			node* prev = NULL;
// 			while(temp != NULL){
// 				if(temp->st.top() > arr[i]){
// 					temp->st.push(arr[i]);
// 					if(prev != NULL)
// 					 	temp->prev = prev;
// 					else
// 						temp->prev = root;
// 					break;
// 				}else{
// 					prev = temp;
// 					temp = temp->link;	
// 				}
// 			}
// 			if(temp == NULL){
// 			    node* newAddress = new node();
// 				newAddress->st.push(arr[i]);
// 				prev->link = newAddress;
// 				newAddress->prev = prev;
// 			}	
// 		}
// 	}
//   cout << endl;
//   cout << endl;
// 	int i = 0;
// 	while(root != NULL){
// 		node* temp = root;
// 		node* address = NULL;
// 		int min = INT_MAX;
// 		while(temp != NULL){
// 			if(min > temp->st.top()){
// 				min = temp->st.top();
// 				address = temp;
// 			}
// 			temp = temp->link;
// 		}
// 		arr[i] = min;
// 		i++;
// 		address->st.pop();
// 		if(address->st.size() == 0){
// 			if(root == address){
// 				root = address->link;
// 			}else{
// 				address->prev->link = address->link;
// 			}
// 		}
// 	}
// }



// int main(){
// 	int n;
// 	cin >> n;
// 	int* arr = new int[n];
// 	for(int i = 0 ; i < n ; i++){
// 		cin >> arr[i];
// 	}
// 	patienceSort(arr,n);
// 	for(int i=0;i<n;i++){
// 		cout << arr[i] << " ";
// 	}
// 	return 0;
// }





// int lcs(int* arr,int n1,int *arr1,int n2){
// 	if(n1 == 0 || n2 == 0){
// 		return 0;
// 	}

// 	if(arr[n1-1] == arr1[n2-1]){
// 		return 1 + lcs(arr,n1-1,arr1,n2-1);
// 	}else{
// 		int a = lcs(arr,n1,arr1,n2-1);
// 		int b = lcs(arr,n1-1,arr1,n2);
// 		return (a > b)?a:b;
// 	}
// }


// int main(){
// 	int arr[] = {3,7,10,40,50,80};
// 	int arr1[] = {50,3,10,7,40,80};
// 	int n = sizeof(arr)/sizeof(int);
// 	int ans = lcs(arr,n,arr1,n);
// 	cout << " longest common subsequnces are : "<< ans << endl;
// 	return 0;
// }








// int longestIncreasingSubsequences(int *arr,int s,int n,int prevIndex,int currLen){
// 	if(s == n){
// 		return currLen;
// 	}

// 	if(prevIndex == -1){
// 		int res1 = longestIncreasingSubsequences(arr,s+1,n,s,currLen+1);
// 		int res2 = longestIncreasingSubsequences(arr,s+1,n,prevIndex,currLen);
// 		if(res1 > res2){
// 			return res1;
// 		}
// 		return res2;
// 	}
// 	else{
// 		int res1,res2;
// 		res1 = -1;
// 		res2 = 0;
// 		if(arr[s] > arr[prevIndex]){
// 		 res1 = longestIncreasingSubsequences(arr,s+1,n,s,currLen+1);
// 		}
// 		 res2 = longestIncreasingSubsequences(arr,s+1,n,prevIndex,currLen);
// 		if(res1 != -1){
// 			if(res1 > res2){
// 			return res1;
// 		}
// 		 	return res2;
// 		}else{
// 			return res2;
// 		}
// 	}
// }

// int lcs(int *arr,int n){
// 	int *dp = new int[n];
// 	dp[0] = 1;
// 	for(int i = 1 ; i < n ; i++){
// 		int max = INT_MIN;
// 		for(int j = i-1; j >= 0 ; j--){
// 			if(arr[i] > arr[j]){
// 				max = (max < dp[j])?dp[j]:max;
// 			}
// 		}
// 		dp[i] = max + 1;
// 	}

// 	for(int i = 0;i<n;i++){
// 		cout << dp[i] << " ";
// 	}

// 	return dp[n - 1];
// }

// int main(){
// 	int n;
// 	cin >> n;
// 	int *arr = new int[n];
// 	for(int i = 0;i<n;i++){
// 		cin >> arr[i];
// 	}

// 	int ans = lcs(arr,n);
// 	cout << " \nlongest increasing SubSequence : "<< ans << endl;
//  	return 0;
// }










// int recursion(int values[],int weight[],int knapSack,int n,int currProfit){
// 	if(n == 0 || knapSack == 0){
// 		return currProfit;
// 	}else if(knapSack < 0){
// 		return -1;
// 	}

// 	if(weight[n-1] > knapSack){
// 		return recursion(values,weight,knapSack, n-1 ,currProfit);
// 	}
// 	else{
// 	int ans = recursion(values,weight,knapSack - weight[n-1],n-1,currProfit+values[n-1]);
// 	int ans1 = recursion(values,weight,knapSack,n-1,currProfit);
// 	return (ans > ans1)?ans:ans1;

// 	}
// }

// int bottomUp(int values[],int weight[],int knapsack,int n,int profit){

// 	int dp[n+1][knapsack + 1];
// 	for(int i = 0;i<=n;i++){
// 		for(int j = 0;j<=knapsack;j++){
// 			dp[i][j] = 0;
// 		}
// 	}

// 	for (int i = 1; i <= n; i++)
// 	{
// 		for(int j = 1;j<= knapsack;j++){
// 			if(weight[i-1] <= j){
// 				dp[i][j] = (dp[i-1][j] < (values[i]+dp[i-1][j - weight[i-1]]))?values[i-1]+dp[i-1][j - weight[i-1]]:dp[i-1][j];
// 			}else{
// 				dp[i][j] = dp[i-1][j];
// 			}
// 		}
// 	}
	
// 	for(int i = 0;i<=n;i++){
// 		for(int j = 0 ; j <= knapsack ; j++){
// 			cout << dp[i][j] << " ";
// 		}
// 		cout << endl;
// 	}
// 	return dp[n][knapsack];
// }

// int recursionMemoization(int **dp,int values[],int weight[],int knapSack,int n,int currProfit){
// 	if(n == 0 || knapSack == 0){
// 		return currProfit;
// 	}else if(knapSack < 0){
// 		return -1;
// 	}
// 	if(dp[n-1][knapSack] != 0){
// 		return dp[n - 1][knapSack];
// 	}

// 	if(weight[n-1] > knapSack){
// 		dp[n-1][knapSack] = recursion(values,weight,knapSack, n-1 ,currProfit);
// 	}else{
// 		int ans = recursionMemoization(dp,values,weight,knapSack - weight[n-1],n-1,currProfit+values[n-1]);
// 		int ans1 = recursionMemoization(dp,values,weight,knapSack,n-1,currProfit);
// 		dp[n-1][knapSack]  = (ans > ans1)?ans:ans1;
// 	}
// 	return dp[n-1][knapSack];
// }

// int main(){
// 	int values[] = {60,100,150};
// 	int weight[] = {15,30,45};
// 	int knapSack = 50;
// 	int **dp = new int*[3];
// 	for(int i=0;i<3;i++){
// 		dp[i] = new int[51];
// 	}
// 	for(int i = 0;i<3;i++){
// 		for(int j = 0 ; j <= 50 ; j++){
// 			dp[i][j] = 0;
// 		}
// 	}
// 	int ans = bottomUp(values,weight,knapSack,3,0);
// 	if(ans != -1){
// 		cout << "maximum profit we can obtain : "<< ans << endl;
// 	}
// 	return 0;
// }













// int coinChangeProblem(int **dp,int* arr,int n,int val){
// 	if(val == 0){
// 		return 1;
// 	}
// 	if(val < 0 || n == 0){
// 		return 0;
// 	}
// 	if(dp[n-1][val] > 0){
// 		return dp[n-1][val];
// 	}
// 	dp[n-1][val] = coinChangeProblem(dp,arr,n,val-arr[n-1]) + coinChangeProblem(dp,arr,n-1,val);
// 	return dp[n-1][val];
// }

// int coinChangeProblem(int *arr,int n,int val){
// 	if(n == 0 || val == 0){
// 		return 0;
// 	}

// 	int dp[n][val+1];
// 	for(int i = 0;i<n;i++){
// 		for(int j=0;j<=val;j++){
// 			dp[i][j] = 0;
// 		}
// 	}
// 	for(int i = 0 ; i < n ; i++){

// 		cout << i << " - > "<<endl;
// 		for(int j = 0 ; j <= val; j++){
// 			if(i == 0 && j == 0){
// 				dp[i][j] = 1;
// 			}else if(i == 0){
// 				if(arr[i] <= j)
// 					dp[i][j] = dp[i][j - arr[i]];
// 			}else if(j == 0){
// 				dp[i][j] = dp[i-1][j];
// 			}else{
// 				if(arr[i] > j){
// 					dp[i][j] = dp[i-1][j]; 
// 				}else{
// 					dp[i][j] = dp[i-1][j] + dp[i][j - arr[i]];
// 				}
// 			}
// 			cout << dp[i][j] << " ";
// 		}
// 		cout << endl;
// 	}
// 	for(int i = 0; i < n ; i++){
// 		for(int j=0;j<=val;j++){
// 			cout << dp[i][j]<< " ";
// 		}
// 		cout << endl;
// 	}
// 	return dp[n-1][val];
// }

// int bestAppraoach(int *coins,int n,int val){
// 	if(n == 0 || val == 0){
// 		return 0;
// 	}
// 	int *dp = new int[val + 1];
// 	for(int  i = 0;i<=val;i++){
// 		dp[i] = 0;
// 	}
// 	dp[0] = 1;
// 	for(int i = 0 ; i<n;i++){
// 		for(int j=coins[i];j <= val ; j++){
// 			dp[j] += dp[j - coins[i]];
// 		}
// 	}
// 	return dp[val];
// }

// int main(){
// 	int n,val;
// 	cin >> n >> val;
// 	int *arr = new int[n];
// 	for(int i=0;i<n;i++){
// 		cin >> arr[i];
// 	}
// 	int **dp1 = new int*[n];
// 	for(int i = 0;i<n;i++){
// 		dp1[i] = new int[val+1];
// 	}
// 	for(int i = 0; i < n ; i++){
// 		for(int j=0;j<=val;j++){
// 			dp1[i][j] = 0;
// 		}
// 	}
// 	int ans = bestAppraoach(arr,n,val);
// 	// int Ans = coinChangeProblem(dp1,arr,n,val);
// 	cout<<ans<<endl;
// 	return 0;
// }



















// #include<bits/stdc++.h>
// using namespace std;

// class Global{
// 	public:
// 		int minimumSquare(int x){
// 			if(x == 0 || x == 1 || x == 2 || x == 3){
// 			return x;
// 		}
// 		int min = INT_MAX;
// 		for(int i = 1; i <= sqrt(x);i++){
// 			int temp =  minimumSquare(x-(i*i));
// 			if(min > temp){
// 				min = temp;
// 				}
// 			}
// 			return (min + 1);
// 		}

// 		int minimumSquare(int x,int *dp){
// 			if(x == 0 || x == 1 || x == 2 || x == 3){
// 				return x;
// 			}
// 			if(dp[x] != -1){
// 				return dp[x];
// 			}
// 			int min = INT_MAX;
// 			for(int i = 1;i<=sqrt(x);i++){
// 				int smallAns = minimumSquare(x - (i * i),dp);
// 				if(smallAns < min){
// 					min = smallAns;
// 				}
// 			}
// 			dp[x] = min + 1;
// 			return dp[x];
// 		}
// };

// int minimum(int *dp,int x){
// 	if(x == 0 || x == 1 || x == 2 || x == 3){
// 		return x;
// 	}
// 	for(int i = 4;i<=x;i++){
// 		int min = INT_MAX;
// 		int index = -1;
// 		for(int j = 1;j<=sqrt(i);j++){
// 			if(min > (dp[i - (j*j)])){
// 				min = dp[i - (j*j)];
// 				 index = i - (j*j);
// 			}
// 		}
// 		dp[i] = min + 1;
// 		cout << i << " " << index <<  " + " << dp[i]<<endl;
// 	}
// 	return dp[x];
// }

// int main(){
// 	Global* obj = new Global();
// 	int x;
// 	cin >> x;
// 	int *dp = new int[x+1];
// 	for(int i = 0;i<=x;i++){
// 		dp[i] = -1;
// 	}
// 	dp[0] = 0;
// 	dp[1] = 1;
// 	dp[2] = 2;
// 	dp[3] = 3;
// 	int ans = minimum(dp,x);
// 	cout << " ans : " << ans << endl;

// 	for(int i=0;i<=x;i++){
// 		cout << dp[i] << " ";
// 	}
// 	return 0;
// }

















// // int fib(int n,int* dp){
// // 	if(n == 0 || n == 1){
// // 		return n;
// // 	}
// // 	if(dp[n] != -1){
// // 		return dp[n];
// // 	}
// // 	dp[n] = fib(n-1,dp) + fib(n-2,dp);
// // 	return dp[n];
// // }

// // int fibbonacci(int* dp,int n){
// // 	if(n == 0 || n == 1){
// // 		return n;
// // 	}
// // 	for(int i = 2;i<=n;i++){
// // 		dp[i] = dp[i-1] + dp[i-2];
// // 	}
// // 	return dp[n];
// // }

// // int main(){
// // 	int n;
// // 	cin >> n;
// // 	int *dp = new int[n+1];
// // 	for(int i = 0; i<=n ; i++){
// // 		dp[i] = -1;
// // 	}
// // 	dp[0] = 0;
// // 	dp[1] = 1;
// // 	int ans = fibbonacci(dp,n);
// // 	cout << " ans : "<< ans << endl;
// // 	for(int i=0;i<=n;i++){
// // 		cout << dp[i] << " ";
// // 	}

// // 	return 0;
// // }
















// // #include<iostream>
// // #include<limits.h>
// // using namespace std;
// // int count = 0;
// // int mat[4][4] = {
// // 	{0,20,42,25},
// // 	{20,0,30,34},
// // 	{42,30,0,10},
// // 	{25,34,10,0}
// // };

// // int min(int a,int b){
// // 	return (a > b)?b:a;
// // }

// // int tsp(int dp[4][16],int mask,int src,int last,int init){
// // 	count++;
// // 	if(mask == (1 << 4)-1){
// // 		return mat[src][init];
// // 	}
// // 	if(dp[src][mask] != 0){
// // 		return dp[src][mask];
// // 	}

// // 	int ans = INT_MAX;
// // 	for(int city=0;city<4;city++){
// // 		if((mask & (1 << city)) == 0){
// // 			 ans = min(ans ,tsp(dp,mask|(1 << city),city,last,init)) + mat[src][city];
// // 		}
// // 	}
// // 	dp[src][mask] = ans;

// // 	return ans;
// // }

// // int main(){
// // 	int src;
// // 	cin >> src;
// // 	int allVisitedMask = 0;
// // 	int temp = 1;
// // 	int prev = temp;
	
// // 	int dp[4][16];
// // 	for(int i=0;i<4;i++){
// // 		for(int j = 0;j<16;j++){
// // 			dp[i][j] = 0;
// // 		}
// // 	}	
// // 	int ans = tsp(dp,src,src,allVisitedMask,src);
// // 	cout << " minimum answer to reach all the cities are : "<<ans<<endl;
// // 	cout << " count : "<< count<<endl;

	
// // 	return 0;
// // }












//--------------------
// using memoization 
// int MinimumJumpsRequired(int *arr,int n,int index,int *dp){
// 	if(index >= n-1){
// 		return 0;
// 	}

// 	if(dp[index] != -1){
// 		return dp[index];
// 	}

// 	int min = INT_MAX;
// 	for(int i = 1;i <= arr[index];i++){
// 		int temp =  1 + MinimumJumpsRequired(arr,n,index+i,dp);
// 		if(min > temp){
// 			min = temp;
// 		}
// 	}

// 	if(min == INT_MAX){
// 		return INT_MAX;
// 	}
// 	cout << index << " -> "<<min<<endl;
// 	dp[index] = min;
// 	return dp[index];
// }

// // bottom up approach
// int MinJumpProblem(int arr[],int n,int index){
// 	if(n == 0)
// 	{
// 		return INT_MAX;
// 	}

// 	if(n == 1){
// 		return 0;
// 	}

// 	int dp[n];
// 	for(int i = 0 ; i < n ;i++){
// 		dp[i] = INT_MAX;
// 	}
// 	dp[n-1] = 0;
// 	cout << (n - 1) << " -> " << dp[n - 1]<<endl;
// 	for(int i = n-2 ; i >= 0 ; i--){
// 		int min = INT_MAX;
// 		for(int jump = 1 ; (jump <= n - 1) && (jump <= arr[i]) ; jump++){
// 			if(min > dp[i+jump]){
// 				min = dp[i + jump];
// 			}
// 		}
// 		if(min == INT_MAX){
// 			return INT_MAX;
// 		}
// 		dp[i] = min + 1;
// 		cout << i << " -> " << dp[i]<<endl;
// 	} 

// 	for(int i=0;i<n;i++){
// 		cout << dp[i] << " ";
// 	}

// 	return dp[0];
// }

// int greedyApproach(int arr[],int n,int index){
// 	// maximum jump I can make from the current index;
// 	int prev = 0;
// 	// how many jumps I take to reach at the final index
// 	int jump = 0;
// 	// maximum range 
// 	int maxRange = 0;

// 	for(int i=0;i<n;i++){
// 		if(i > prev){
// 			jump++;
// 			prev = maxRange;
// 		}
// 		maxRange = (maxRange > i + arr[i])?maxRange:(i + arr[i]);
// 	}
// 	return jump;

// }
// int main(){
// 	int n;
// 	cin >> n;
// 	int *arr = new int[n];
// 	for(int i=0;i<n;i++){
// 		cin >> arr[i];
// 	}
// 	int ans = greedyApproach(arr,n,0);
// 	cout << "\n minimum jumps required to reach at the end position : "<<ans;
	
// 	return 0;
// }
#include<bits/stdc++.h>
using namespace std;



// longest common sequences....

int lcs(int* arr,int n1,int *arr1,int n2){
	if(n1 == 0 || n2 == 0){
		return 0;
	}

	if(arr[n1-1] == arr1[n2-1]){
		return 1 + lcs(arr,n1-1,arr1,n2-1);
	}else{
		int a = lcs(arr,n1,arr1,n2-1);
		int b = lcs(arr,n1-1,arr1,n2);
		return (a > b)?a:b;
	}
}


int main(){
	int arr[] = {3,7,10,40,50,80};
	int arr1[] = {50,3,10,7,40,80};
	int n = sizeof(arr)/sizeof(int);
	int ans = lcs(arr,n,arr1,n);
	cout << " longest common subsequnces are : "<< ans << endl;
	return 0;
}










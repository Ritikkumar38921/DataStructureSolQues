#include<bits/stdc++.h>
using namespace std;

//longest increasing subsequences with patience sorting technique

struct node{
	node* link;
	node* prev;
	stack<int> st;
	node(){
		link = NULL;
		prev = NULL;
	}
};

void printFunc(node* root){
	int i = 0;
	node* t = root;
	while(t != NULL){
		cout << i << " -> \n ";
		while(t->st.size() > 0){
			cout << t->st.top() << " ";
			t->st.pop();
		}
		cout << endl;
		i++;
		t = t->link;
	}
}
int  patienceSort(int* arr,int n){
	if(n == 0 || n == 1){
		return n;
	}
	struct node* root;
	root = NULL;
	for(int i=0;i<n;i++){
		if(root == NULL){
			root = new node();
			root->st.push(arr[i]);
			root->prev = root;
		}else{
			node* temp = root;
			node* prev = NULL;
			while(temp != NULL){
				if(temp->st.top() > arr[i]){
					temp->st.push(arr[i]);
					if(prev != NULL)
					 	temp->prev = prev;
					else
						temp->prev = root;
					break;
				}else{
					prev = temp;
					temp = temp->link;	
				}
			}
			if(temp == NULL){
			    node* newAddress = new node();
				newAddress->st.push(arr[i]);
				prev->link = newAddress;
				newAddress->prev = prev;
			}	
		}
	}
	int count = 0;
	while(root != NULL){
		cout << root->st.top() << " ";
		count++;
		root = root->link;
	}
	return count;
}




int LIS(int *arr,int n){
   return patienceSort(arr,n);
}

int main(){
	int n;
	cin >> n;
	int* arr = new int[n];
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	int ans = LIS(arr,n);
	cout << " \nlongest increasing subSequence is "<< ans << endl;
	return 0;
}





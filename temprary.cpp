#include<bits/stdc++.h>
using namespace std;

//  patience sort
// this is sorting technique which is based on the concept of tash
// we can only put a value over other no. if that no. is smaller than existed top value
// of the line.
// we only compare the top value of all pile and if that value is larger as compared to 
// other then make the separate pile.



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
void patienceSort(int* arr,int n){
	if(n == 0 || n == 1){
		return;
	}else if(n == 2){
		if(arr[0] > arr[1]){
			int temp = arr[0];
			arr[0] = arr[1];
			arr[1] = temp;
		}
		return;
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
  cout << endl;
  cout << endl;
	int i = 0;
	while(root != NULL){
		node* temp = root;
		node* address = NULL;
		int min = INT_MAX;
		while(temp != NULL){
			if(min > temp->st.top()){
				min = temp->st.top();
				address = temp;
			}
			temp = temp->link;
		}
		arr[i] = min;
		i++;
		address->st.pop();
		if(address->st.size() == 0){
			if(root == address){
				root = address->link;
			}else{
				address->prev->link = address->link;
			}
		}
	}
}



int main(){
	int n;
	cin >> n;
	int* arr = new int[n];
	for(int i = 0 ; i < n ; i++){
		cin >> arr[i];
	}
	patienceSort(arr,n);
	for(int i=0;i<n;i++){
		cout << arr[i] << " ";
	}
	return 0;
}






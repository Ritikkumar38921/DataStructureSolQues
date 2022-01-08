#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    node* left;
    node* right;
    node(){
        this->left = this->right = NULL;
    }
};

void insert(int a,node* root){
    for(int i = 31;i>=0;i--){
        int bit = ((a >> i)&1);
        if(bit == 0){
            if(root->left == NULL){
                root->left = new node();
            }
            root = root->left;
        }else{
            if(root->right == NULL){
                root->right = new node();
            }
            root = root->right;
        }
    }
}

bool search(int value,node* root){
    for(int i = 31;i >= 0;i--){
       int bit = (value & (1 << i));
       if(bit == 0){
           if(root->left == NULL){
               return false;
           }
           root = root->left;
       }else{
           if(root->right == NULL){
               return false;
           }
           root = root->right;
       }
    }
    return true;
}

int maximumXor(int arr[],int n,node* root){
    if(n == 0 || n == 1){
        return -1;
    }
    int maxXor = INT_MIN;
    for(int i = 0;i < n; i++){
        int ele = arr[i];
        int currXor = 0;
        for(int i = 31 ; i >= 0 ; i--){
            int bit = value & (1 << i);
            if(bit == 0){
                if(root->right != NULL){
                    currXor = (currXor ^ (1 << i));
                    root = root->right;
                }else{
                    root = root->left;
                }
            }else{
                if(root->left != NULL){
                    root = root->left;
                }else{
                    root = root->right;
                }
            }
        }
    }

}


int main(){
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    node* root = new node();
    for(int i = 0 ; i < n; i++){
        insert(arr[i],root);
    }
    return 0;
}



#include<bits/stdc++.h>
using namespace std;
const int alfabetSize = 26;

// this is a structure of trie
struct trie{
   struct trie *child[26];
   bool isendofword = false; 
};

// this is give us root pointer
trie* getrootnode(){
   struct trie* root = new trie();
   for(int i=0;i<alfabetSize;i++){
      root->child[i] = NULL;
   }
   root->isendofword = false;
   return root;
}

void insert(string str,struct trie* root){
    struct trie* head = root;
    for(int i=0;i<str.length();i++){
       int index = str[i] - 'a';
       if(head->child[index] == NULL){
          head->child[index] = getrootnode();
       }
       head = head->child[index];
    }
   head->isendofword = true;
}

bool search(string str,struct trie* root){
   trie* head = root;
   for(int i=0;i<str.size();i++){
      int index = str[i] - 'a';
      if(head->child[index] == NULL)
        return false;
      head = head->child[index];
   }
   if(head->isendofword == true)
   return true;
   else
    return false;
}

int main(){
   string arr[] = {"the","these","ritik","rajat"};
   struct trie* root = getrootnode();

   for(int i=0;i<sizeof(arr)/sizeof(string);i++){
      insert(arr[i],root);
   }
   if(search("ritika",root)){
      printf("present");
   }else{
      cout << " not present ";
   }
   return 0;
}
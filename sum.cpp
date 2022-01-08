#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

this question says suppose you have given words of dictionary
and find the concatinated words from the dictionary.
concatinated words means that if we pick atleast two words from the 
dictionary and by doing concatination we formation a new words
then ,if we able to get that word in the dictionary words then 
that is the one of the possible answer.


// make the trienode
struct TrieNode{
  bool end;
  TrieNode* children[26];
  TrieNode(){
    this->end = false;
    for(int i=0;i<26;i++){
      this->children[i] = NULL;
    }
  }
};

bool compare(string a,string b){
  if(a.size() < b.size()){
    return true;
  }else{
    return false;
  }
}

// insert only those string whose length is less than minLength.

void insert(string str,TrieNode* root){
    int len = str.size();
    for(int i = 0;i < len;i++){
      int index = str[i] - 'a';
      if(root->children[index] == NULL){
        root->children[index] = new TrieNode();
      }
      root = root->children[index];
    }
    root->end = true;
}


//this function search that does provided string is present 
// in the trie or not
bool search(string str,TrieNode* root,int index){
  int len = str.size();
  TrieNode* temp = root;
  for(int i = index;i < len; i++){
    int idx = str[i] - 'a';
    if(temp->end == true){
      bool t1 =  search(str,root,i);
      if(t1){
        return t1;
      }
    }
    if(temp->children[idx] == NULL){
      return false;
    }else{
      temp = temp->children[idx];
    }
  }
  return true;
}

// ececution of the program starts over here.
int main(){
  string str[] = {"cat","cats","catsdogcats","dog","dogcatsdog","hippoptamuses","rat","ratcatdogcat"};
  int n = sizeof(str)/sizeof(string);
  sort(str,str+n,compare);
  vector<string> vec;
  TrieNode* root = new TrieNode();
  cout << endl;
  int min = INT_MAX;
  for(int i=0;i<n;i++){
    if(min == INT_MAX){
      min = str[i].length();
      insert(str[i],root);
    }else{
      if(str[i].length() < (2*min)){
        insert(str[i],root);
        min = (min > str[i].length())?str[i].length():min;
      }else{
        bool response = search(str[i],root,0);
        if(response){
          vec.push_back(str[i]);
        }
      }
    }
  }

  for(int i = 0;i<vec.size();i++){
    cout << vec[i] << " ";
  }
  return 0;
}























// #include<bits/stdc++.h>
// using namespace std;
// int removeEdges = 0;


// int removeMaxEdges(map<int,vector<int>> mp,int n,int e,int *s,int src,int edges){
//   if(mp[src].size() <= 0)
//   return 1;
//  for(auto i=0;i<mp[src].size();i++){
//    int smallAns = removeMaxEdges(mp,n,e,s,mp[src][i],edges+1);
//    s[src] += smallAns;
//  }
//  if(s[src]%2 == 0){
//    cout <<"source is "<< src <<" -> "<<s[src]<<" -> "<<(removeEdges+1)<<endl; 
//    removeEdges++;
//   return 0;
//  }
//  return s[src];
// }

// int main(){
//   int n,e;
//   cin >> n >> e;
//   map<int,vector<int>> mp;
//   for(int i=0;i<e;i++){
//     int a,b;
//     cin >> a >> b;
//     mp[b].push_back(a);
//   }
//   int *size = new int[n];
//   for(int i=0;i<n;i++){
//     size[i] = 1;
//   }
//    for(auto i = mp.begin();i != mp.end();i++){
//      cout<< i->first << " -> ";
//      for(int j = 0;j<i->second.size();j++){
//        cout << i->second[j] << " , ";
//      }
//      cout<<endl;
//    }
//   int size_of_1 = removeMaxEdges(mp,n,e,size,1,0);
//   cout << "answer is "<<(removeEdges-1);
//   return 0;
// //   10 9
// // 2 1
// // 3 1
// // 4 3
// // 5 2
// // 6 1
// // 7 2
// // 8 6
// // 9 8
// // 10 8

// }
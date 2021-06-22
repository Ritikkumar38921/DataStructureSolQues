
#include<stdio.h>
#include<conio.h>
int *ans;

void build(int s,int e,int ind,int *arr){
  if(s == e){
    ans[ind] = arr[s];
    return;
  }
  int mid = (s+e)/2;
  build(s,mid,2*ind+1,arr);
  build(mid+1,e,2*ind+2,arr);
  ans[ind] = (ans[2*ind+1]<ans[2*ind+2])?ans[2*ind+1]:ans[2*ind + 2];
}

void update(int* lazy,int start,int end,int val,int s,int e,int node){
   if(start == s && end == e){
      lazy[node] = val;
      return;
   }
   int mid = (s + e)/2;
   if(start <= mid && end <= mid){
    update(lazy,start,end,val,s,mid,2*node + 1);
   }else if(start >= mid+1 && end >= mid + 1){
    update(lazy,start,end,val,mid + 1,e,2*node + 2);
   }else{
   update(lazy,start,mid,val,s,mid,2*node + 1);
   update(lazy,mid + 1,end,val,mid + 1,e,2*node + 2);
  }
}

int range(int qs,int qe,int node,int s,int e,int *lazy){
   if(qs > qe)
   return 0;
   if(lazy[node] != 0){
    lazy[2*node + 1] += lazy[node];
    lazy[2*node + 2] += lazy[node]; 
    lazy[node] = 0;
   }
    if(qs < s|| qe > e)
    return 0;
   int mid = (s+e)/2;
   if(qs == s && qe == e){
     ans[node] += lazy[node];
     return ans[node];  
   }else if(qs <= mid && qe <= mid){
     return range(qs,qe,2*node + 1,s,mid,lazy);
   }else if(qs >= s && qe >= e){
     return range(qs,qe,2*node + 2,mid+1,e,lazy);
   }else {
    int c1 = range(qs,mid,2*node + 1,s,mid,lazy);
    int c2 = range(mid+1,qe,2*node + 2,mid+1,e,lazy);
    return (c1 < c2)?c1:c2;
   }

}
int main(){
  int n;
  scanf("%d",&n);
  int *arr = new int[n];
  for(int i=0 ; i < n ; i++){
    scanf("%d",&arr[i]);
  }
  ans = new int[4*n];
  int* lazy = new int[4*n];
  for(int i=0;i<4*n;i++){
    ans[i] = 0;
    lazy[i] = 0;
  }
  build(0,n-1,0,arr);
  printf("minimum between 0 to 3 is ",range(0,3,0,0,n-1,lazy));
 
 return 0;
}
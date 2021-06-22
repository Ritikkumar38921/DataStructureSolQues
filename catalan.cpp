#include <iostream>
using namespace std;
 int arr[100000]={0};
int count = 0;

void function(int n){
  if(n<3)
  	return;
  for(int i=2;i<n;i++){
  	int ans = 0;
   for(int j=0;j<i;j++){
           ans += arr[j]*arr[i-1-j];
   }
   arr[i] = ans;
   count++;
  }
}

int catalan(int n){
  if(n == 0 || n==1)
  	return 1;
  arr[0] = 1;
  arr[1] = 1;
  count = 2;
  function(n);
   return arr[n]; 
}
int main(){
    int n;
    cout<<"enter the value of n: ";
    cin >> n;
    int ans = catalan(n);
     cout<<"answer is : "<<ans;
	return 0;
}
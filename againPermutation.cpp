#include<bits/stdc++.h>
using namespace std;

// minimum jumps required

int minimumJumpsReq(vector<int> vec,int n,int x){

    int count = 0;

    for(int i = 0; i < n; i++){
        int q = (vec[i] / x);
        int r = (vec[i] % x);

        if(r == 0){
            count += q;
        }else{
            count += (q + 1);
        }
    }

    return count;
}

int main(){
    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }
    int x;
    cin >> x;
    int ans = minimumJumpsReq(vec,n,x);
    cout << "answer is : "<< ans << endl;
    return 0;
}

// maximum cheats 

int maximumCheats(map<int,vector<int>> mp,map<int,int> front,int node,int ans,int& myAns){  
    int n = mp[node].size();

    if(n == 0){
        return ans;
    }

    bool flag = (front.find(node) != front.end());
    int sum = 0;

    for(int i = 0; i < n; i++){
        if(flag == true){
            int res = maximumCheats(mp,front,mp[node][i],ans,myAns);

            if(res > myAns){
                myAns = res;
            }
        }else{
            int res = maximumCheats(mp,front,mp[node][i],ans + 1,myAns);
            sum += res;
        }
    }

    if(flag == true){
        return 0;
    }else{
        return sum;
    }
}

int main(){
    map<int,vector<int>> mp;
    map<int,int> front;
    
    int no;
    cin >> no;
    int f;
    cin >> f;
    vector<pair<int,int>> input1;
    vector<int> input2;

    for(int i = 0; i < no; i++){
        int a,b;
        cin >> a >> b;
        input1.push_back({a,b});
    }

    for(int i = 0; i < f; i++){
        int a;
        cin >> a;
        input2.push_back(a);
    }
    int n1 = input1.size();
    int n2 = input2.size();
    
    for(int i = 0; i < n1; i++){
        mp[input1[i].first].push_back(input1[i].second);
    }

    for(int i = 0; i < n2; i++){
        front[input2[i]] = 1;
    }
    int myAns = 0;

    int ans = maximumCheats(mp,front,0,0,myAns);
    if(ans > myAns){
        myAns = ans;
    }
    cout << myAns << endl;

    return 0;
}

// no of ways to arrange the houses

int NoOfWaysOfArrangement(int n){
    if(n == 0){
        return 0;
    }

    if(n == 1){
        return 1;
    }else if(n == 2){
        return ((n + 1) * (n + 1));
    }

    long long sum = 0;
    int range = 0;
    if((n & 1) == 1){
        range = (n / 2) + 1;
    }else{
        range = (n / 2);
    }

    vector<long long> prod(n+1,0);
    prod[1] = 1;
    prod[2] = 2;

    for(int i = 3; i <= n; i++){
        prod[i] = (i * prod[i - 1]);
    }

    sum = (1 + n);

    for(int i = 2; i <= range; i++){
        long long ans = (prod[n])/(prod[i]);
        long long q = ans / prod[n - i];
        int myAns = q - (n - 1);
        sum += myAns;
    }

    return int(sum * sum); 


}

int main(){
    int n;
    cin >> n;
    int ans = NoOfWaysOfArrangement(n);
    cout << "answer is : " << ans << endl;
    return 0;
}
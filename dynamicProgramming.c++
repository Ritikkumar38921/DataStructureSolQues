#include<bits/stdc++.h>
using namespace std;

int main(){
    string str1;
    string str2;
    cin >> str1 >> str2;
    int c1;
    cin >> c1;
    int c2;
    cin >> c2;
    int n1 = str1.length();
    int n2 = str2.length();
    int mat[n1][n2] = {0};
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            if(i==0){
                if(str1[i] == str2[j]){
                    mat[i][j] = 1;
                }
                else{
                    if(j > 0)
                       mat[i][j] = mat[i][j-1];
                }
            }else{
                if(j == 0){
                    mat[i][j] = mat[i-1][j];
                }else{
                    if(str1[i] != str2[j]){
                    mat[i][j] = (mat[i][j-1] > mat[i-1][j])?mat[i][j-1]:mat[i-1][j];
                    }else{
                        mat[i][j] = (mat[i][j-1] > mat[i-1][j])?mat[i][j-1]:mat[i-1][j];
                        mat[i][j] += 1;
                    }
                }
            }
        }
    }

    string matrix[n1][n2] = {""};

    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            if(i==0){
                if(str1[i] == str2[j]){
                    matrix[i][j] = str1[i];
                }
                else{
                    if(j > 0)
                       matrix[i][j] = matrix[i][j-1];
                }
            }
            else{
                if(j == 0){
                    matrix[i][j] = matrix[i-1][j];
                }else{
                    if(str1[i] != str2[j]){
                    matrix[i][j] = (mat[i][j-1] > mat[i-1][j])?matrix[i][j-1]:matrix[i-1][j];
                    }else{
                        matrix[i][j] = (mat[i][j-1] > mat[i-1][j])?matrix[i][j-1]:matrix[i-1][j];
                        matrix[i][j] = matrix[i][j] + str1[i];
                    }
                }
            }
        }
    }
    string s = matrix[n1-1][n2-1];
    cout << s;
    int j = 0;
    int cost = 0;
    for(int i=0;i<str1.length();i++){
        if(j > (s.length()-1)){
            cost += c1;
        }
        else if(s[j] != str1[i]){
            cost += c1;
        }else{
        j++;
        }
    }
    cout << "cost = "<<cost <<endl;
    j = 0;
    for(int i=0;i<str1.length();i++){
        if(j > (s.length()-1)){
            cost += c2;
        }
        else if(s[j] != str2[i]){
            cost += c2;
        }else{
          j++;
        }
    }
    cout << " longest common subsequence is "<< matrix[n1-1][n2-1]<<endl;
    cout << " longest common subsequence length is "<<mat[n1-1][n2-1]<<endl;
    cout << " the minimum cost required to make both the string identical is "<<cost <<endl;
    return 0;
}
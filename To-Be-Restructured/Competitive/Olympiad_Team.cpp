//https://codeforces.com/problemset/problem/490/A
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    map<int,vector<int>> ht;
    ht[2]={},ht[1]={},ht[3]={};
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        ht[temp].push_back(i+1); 
    }
    int teams=min(ht[2].size(),min(ht[1].size(),ht[3].size()));
    cout<<teams<<endl;
    int i=0,j=0,k=0;
    while(teams--){
        cout << ht[1][i++] << " " << ht[2][j++] << " " << ht[3][k++] << endl;
    }
    return 0;
}
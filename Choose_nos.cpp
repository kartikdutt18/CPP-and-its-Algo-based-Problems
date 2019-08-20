//https://codeforces.com/contest/1206/problem/A
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    set<int> a;
    set<int> b;
    int n;
    cin>>n;
    vector<int> A;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        A.push_back(temp);
        a.insert(temp);
    }
    int m;
    cin>>m;
    vector<int> B;
    for(int i=0;i<m;i++){
        int temp;
        cin >> temp;
        B.push_back(temp);
        b.insert(temp);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int cur_sum=A[i]+B[j];
            if(a.count(cur_sum)==0 && b.count(cur_sum)==0){
                cout<<A[i]<<" "<<B[j]<<endl;
                return 0;
            }
        }
    }
    cout<<"-1"<<endl;
    return 0;
}
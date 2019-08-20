//https://codeforces.com/contest/1206/problem/B
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> A;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        A.push_back(temp);
    }
    int odd=0;
    int zero=0;
    int tot_sum=0;
    vector<int> B;
    for(int i=0;i<n;i++){
        if(A[i]<0) odd++;
        else if(A[i]==0) zero++;
        B.push_back(abs(A[i])-1);
        tot_sum+=B.back();
    }

    cout<<tot_sum<<endl;
    return 0;
}
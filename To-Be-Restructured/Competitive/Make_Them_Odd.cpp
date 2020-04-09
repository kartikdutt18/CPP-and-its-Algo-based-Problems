#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long long count_moves(vector<int> v,int n){
    map<int,int> ht;
    long long ans=0;
    for(auto i: v) if(i%2==0)ht[i]++;
    while(!ht.empty()){
        auto i=ht.rbegin();
        if((i->first/2)%2==1){
            ht.erase(i->first);
        }
        else{
            ht[i->first/2]+=i->second;
            ht.erase(i->first);
        }
        ans++;
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        cout<<count_moves(v,n)<<endl;
    }
    return 0;
}
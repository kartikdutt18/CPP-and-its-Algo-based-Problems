//https://codeforces.com/contest/1257/problem/C
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ans=INT_MAX;
        vector<int>arr(n);
        for (int i = 0; i<n; cin>> arr[i], i++);
        int j=0;
        deque<int> dq;
        map<int,int> ht;
        for(j=0;j<n;j++){
            if(ht.count(arr[j])){
                while(!dq.empty() && dq.front()<ht[arr[j]]) dq.pop_front();
                ans=min(ans,(int)dq.size()+1);
               
            }
            ht[arr[j]]=j;
            dq.push_back(j);
        }
        if(ans==INT_MAX) cout<<-1<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}
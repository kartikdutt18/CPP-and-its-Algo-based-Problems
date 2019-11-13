//https://codeforces.com/contest/1257/problem/D
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool compare(vector<long long> a,vector<long long> b){
    if(a[1]==b[1]) return a[0]>b[0];
    return a[1]>b[1];
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        deque<long long> monst;
        for(int i=0;i<n;i++){
            long long temp;
            cin>>temp;
            monst.push_back(temp);
        }
        int m;
        cin>>m;
        vector<vector<long long> > heros(m,vector<long long>(2,0));
        for(int i=0;i<m;i++)
            cin >> heros[i][0]>>heros[i][1];
        sort(heros.begin(),heros.end(),compare);
        int j=0;
        int ans=0;
        while(j<n){
            int i=0;
            while(i<m && heros[i][0]<monst[j]) i++;
            if(i>=m){
                ans=-1;
                break;
            }
            int mon=heros[i][1];
            while(mon>0 && heros[i][0]>=monst[j]){
                j++;
                mon--;
                
            }
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
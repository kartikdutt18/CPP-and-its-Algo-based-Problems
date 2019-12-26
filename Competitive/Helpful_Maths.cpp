//https://codeforces.com/problemset/problem/339/A
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s="";
    getline(cin,s);
    vector<string> v;
    for(int i=0;i<s.length();i++){
        if(s[i]!='+') v.push_back(string(1,s[i]));
    }
    sort(v.begin(),v.end());
    string ans="";
    for(auto i: v){
        ans=ans+i+"+";
    }
    ans.pop_back();
    cout<<ans<<endl;
    return 0;
}
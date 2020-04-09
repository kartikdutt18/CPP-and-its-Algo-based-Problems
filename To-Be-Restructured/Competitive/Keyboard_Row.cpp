//https://leetcode.com/problems/keyboard-row/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void checkword(string s,set<char> s1,vector<string> &ans){
    
    for(auto j:s){
        j=tolower(j);
        if(not s1.count(j)) return;
    }
    ans.push_back(s);
}

vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        set<char> s1={'a','s','d','e','f','g','h','j','k','l'};
        set<char> s2={'q','w','e','r','t','y','u','i','o','p'};
        set<char> s3={'z','x','c','v','b','n','m'};
        for(auto i:words){
            char b=tolower(i[0]);
            
            if(s1.count(b)){
                checkword(i,s1,ans);
            }
            else if(s2.count(b)){
                checkword(i,s2,ans);
            }
            else{
                checkword(i,s3,ans);
            }
        }
return ans;}
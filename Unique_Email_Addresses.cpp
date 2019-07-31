//https://leetcode.com/problems/unique-email-addresses/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string cleanEmail(string s){
    string temp="";
    int e=s.find('@');
    for(int i=0;i<e;i++){
        if(s[i]=='+') break;
        if(s[i]=='.') continue;
        else temp+=s[i]; 
    }
    temp+=s.substr(e,s.size()-e-1);
    return temp;
}
int numUniqueEmails(vector<string> &emails)
{
    set<string> s;
    for(auto i:emails){
        s.insert(cleanEmail(i));
    }
    return s.size();
}
//https://hack.codingblocks.com/practice/p/390/351

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isbalanced(string S){
    stack<char> s;
    for(auto i:S){
        if(i=='(' or i=='{' or i=='['){
            s.push(i);
        }
        else if(i==')' and s.top()=='('){
            s.pop();
        }
        else if(i=='}' and s.top()=='{'){
            s.pop();
        }
        else if(i==']' and s.top()=='['){
            s.pop();
        }
    }
return s.empty();}

int main(){
    string s;
    while(s.empty()){
        getline(cin,s);
    }
    if(isbalanced(s)) cout<<"true"<<endl;
    else cout<<"false"<<endl;
    return 0;
}
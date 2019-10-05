//CTCI 3.5
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void sort(stack<int> &s){
    stack<int> temp;
    while(!s.empty()){
        int tmp=s.top();
        s.pop();
        while(!temp.empty() && tmp<temp.top()){
            s.push(temp.top());
            temp.pop();
        }
        temp.emplace(tmp);
    }
    s=temp;
}
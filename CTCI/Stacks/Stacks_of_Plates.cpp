//CTCT 3.3
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class StacksSets{
    vector<stack<int>> sos;
    int size;
    public:
    StacksSets(int sz){
        size=sz;
    }
    void push(int val){
        if(sos.empty() || sos.back().size()>size){
            stack<int> t;
            sos.emplace_back(t);
        }
        sos.back().push(val);
    }
    int pop(){
        if (sos.size() == 0)    return -1;
        if(sos.back().empty())  return -1;
        int val=sos.back().top();
        sos.back().pop();
        if(sos.back().empty()) sos.pop_back();
        return val;
    }
};
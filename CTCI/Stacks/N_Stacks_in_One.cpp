//CTCI 3.1
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct SData{
    int val;
    int NextElement;
    SData(int x,int y): val(x),NextElement(y) {}
};

class Stacks{
    vector<SData> v;
    vector<int> ToS;
    int NextAvailable;
    int n;
    public:
    Stacks(int n){
        this->n=n;
        NextAvailable=0;
        for(int i=0;i<n;i++) ToS.emplace_back(-1);
        for(int i=0;i<2*n+1;i++) v.emplace_back(SData(0,i+1));
        v.back().NextElement=-1;
    }
    void push(int stack,int value){
        if(stack<0 || stack>=n) return;
        if(NextAvailable==-1) return;
        int cur_index=NextAvailable;
        NextAvailable=v[cur_index].NextElement;
        v[cur_index].val=value;
        v[cur_index].NextElement=ToS[stack];
        ToS[stack]=cur_index;

    }
    int pop(int stack){
        if (stack < 0 || stack >= n)
            return -1;
        if(ToS[stack]==-1) return -1;
        int val=v[ToS[stack]].val;
        ToS[stack]=v[ToS[stack]].NextElement;
        v[ToS[stack]].NextElement=NextAvailable;
        NextAvailable=ToS[stack];
        return val;
    }
};
//https://leetcode.com/problems/3sum/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Triplet{
    public:
    bool found;
    vector<vector<int>> vectors;
    set<vector<int>> s;
    Triplet(): found(false) {}
    void flush(){
        for(auto i:s){
            vectors.push_back(i);
        }
    }
    void insert(int a,int b){
        found=true;
        vector<int> v={a,b};
        sort(v.begin(),v.end());
        s.insert(v);
    }
};

Triplet twoSum(map<int,int> ht,int req_sum){
    Triplet t;
    for(auto i:ht){
        ht[i.first]--;
        if (ht.count(req_sum - i.first) && ht[req_sum - i.first] != 0 && i.second != 0)
        {
            t.insert(i.first,req_sum-i.first);
        }
        ht[i.first]++;
    }
    t.flush();
    return t;
}

vector<vector<int>> threeSum(vector<int> &nums)
{
    map<int,int> ht;
    for(auto i: nums) ht[i]+=1;
    
    
    set<vector<int>> ans;
    for(auto i: ht){
        int cur_sum=i.first;
        ht[i.first]--;
        int req_sum=-1*cur_sum;
        auto j=twoSum(ht,req_sum);
        if(j.found){
            for(auto k:j.vectors){
                k.push_back(i.first);
                sort(k.begin(),k.end());
                ans.insert(k);
            }
        }
        ht[i.first]++;
    }
    vector<vector<int>> fin;
    for(auto i: ans){
        fin.push_back(i);
    }
    return fin;
}
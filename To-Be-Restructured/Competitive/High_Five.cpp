//https://leetcode.com/problems/high-five/submissions/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int,priority_queue<int>> mymap;
        for(auto V : items)
            mymap[V[0]].push(V[1]);
        vector<vector<int>> res;
        for(auto &it : mymap){
            int cnt = 0, sum = 0;
            while(!it.second.empty() && cnt < 5){
                sum += it.second.top();
                it.second.pop();
                cnt++;
            }
            res.push_back({it.first,sum/cnt});
        }
        return res;
}

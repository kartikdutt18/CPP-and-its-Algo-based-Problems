//https://leetcode.com/problems/number-of-recent-calls/submissions/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class RecentCounter {
    priority_queue<int,vector<int>,greater<int>> pq;
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        while(!pq.empty() && (-pq.top()+t)>3000){
            pq.pop();
        }
      
        pq.push(t);
        return pq.size();
    }
};
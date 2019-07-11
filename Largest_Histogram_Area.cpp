//https://leetcode.com/problems/largest-rectangle-in-histogram/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> &heights)
{   
    stack<long long int> s;
    long long int max_area=0;
    long long int cur_area=0;
    long long int cnt=0;
    
    while(cnt<heights.size()){
        if(s.empty()||heights[s.top()]<=heights[cnt]){
            s.push(cnt++);
        }
        else{
            long long int top_ind=s.top();
            s.pop();
            long long int w=s.empty()?cnt:cnt-s.top()-1;
            cur_area=heights[top_ind]*w;
            max_area=max(cur_area,max_area);
            
        }
    }
    while(!s.empty()){
        long long int tp=s.top();
        s.pop();
        long long int w = s.empty() ? cnt : cnt - s.top() - 1;
        cur_area=heights[tp]*w;
        max_area = max(max_area, cur_area);
    }
return max_area;}
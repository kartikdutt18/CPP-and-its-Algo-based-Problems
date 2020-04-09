//https://leetcode.com/problems/height-checker

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int heightChecker(vector<int>& heights) {
        if(heights.size()==1) return 0;
        int count=0;
        vector<int> sorted_ht=heights;
        sort(sorted_ht.begin(),sorted_ht.end());
        for(int i=0;i<heights.size();i++){
            if(sorted_ht[i]!=heights[i]) count++;
 
        }
    return count;}
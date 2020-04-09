//https://leetcode.com/problems/container-with-most-water/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int maxArea(vector<int> &heights)
{
    int left=0;
    int max_Area=0;
    int right=heights.size()-1;
    while(left<right){
        max_Area=max(max_Area,min(heights[left],heights[right])*(left-right));
        if(heights[left]<heights[right])
            left++;
        else    
            right--;
    }
    return max_Area;
}
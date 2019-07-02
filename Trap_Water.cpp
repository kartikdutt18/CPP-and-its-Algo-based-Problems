//https://leetcode.com/problems/trapping-rain-water/


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) {
        int n=height.size();
        vector<int>left(n+1,0),right(n+1,0);
        for(int i=0;i<n;i++) {
            if(i!=0) left[i]=max(left[i-1],height[i]);
            else left[i]=height[i];
        }
        for(int i=n-1;i>=0;i--){
            if(i!=n-1) right[i]=max(right[i+1],height[i]);
            else right[i]=height[i];
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=min(left[i],right[i])-height[i];
        }
    return ans;
}
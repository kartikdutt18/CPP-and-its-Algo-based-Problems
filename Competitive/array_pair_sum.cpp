//https://leetcode.com/problems/array-partition-i/

//Greedy Approach

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum=0;
        for(int i=0;i<nums.size();i+=2){
            sum+=min(nums[i],nums[i+1]);
        }
return sum;}

int main(){
    vector<int>arr(5,0);
    arr={1,2,3,4};
    cout<<arrayPairSum(arr);
    return 0;

}
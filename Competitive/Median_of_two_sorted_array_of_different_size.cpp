//https://leetcode.com/problems/median-of-two-sorted-arrays/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int x=nums1.size();
    int y=nums2.size();
    if (x > y) {
            return findMedianSortedArrays(nums2, nums1); // ensures 1st array is smaller than 2nd array
    }
    int s=0;
    int e=x;
    while(s<=e){
        int partitionX=(s+e)/2;
        int partitionY=(x+y+1)/2-partitionX;

        int LeftmaxX=(partitionX==0)?INT_MIN:nums1[partitionX -1];
        int RightminX=(partitionX==x)?INT_MAX:nums1[partitionX];

        int LeftmaxY=(partitionY==0)?INT_MIN:nums2[partitionY -1];
        int RightminY=(partitionY==y)?INT_MAX:nums2[partitionY];

        if(LeftmaxX<=RightminY && RightminX>=LeftmaxY){
            if((x+y)&1){
                return max(LeftmaxX,LeftmaxY);
            }
            else{
                return max(LeftmaxX,LeftmaxY)/2+min(RightminX,RightminY)/2;
            }
        }
        else if (LeftmaxX>RightminX){
            e=partitionX;
        }
        else{
            s=partitionX+1;
        }


    }
}
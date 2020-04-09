//https://leetcode.com/problems/fixed-point/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int fixedPoint(vector<int> &A)
{
    int low=0;
    int high=A.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(mid==A[mid]) return mid;
        if(mid<A[mid])high=mid-1;
        else low=mid+1;
    }
    return -1;
}
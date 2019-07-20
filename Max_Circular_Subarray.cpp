//https://leetcode.com/problems/maximum-sum-circular-subarray/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int Kadane(vector<int> A){
    int cs=A[0];
    int ms=INT_MIN;
    for(int i=1;i<A.size();i++){
        ms=max(ms,cs);
        cs+=A[i];
        if(cs<0){
            cs=0;
        }
    }
    return ms;
}
int maxSubarraySumCircular(vector<int> &A)
{
    return Kadane(A);
}
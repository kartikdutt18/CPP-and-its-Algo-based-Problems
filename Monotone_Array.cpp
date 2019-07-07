//https://leetcode.com/problems/monotonic-array/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;



bool isMonotonic(vector<int>& A) {
        int n=A.size();
        if(n==0 || n==1 || n==2){
            return true;
        }
        bool p1=true;
        bool p2=true;
        for(int i=1;i<A.size();i++){
            p1=p1&(A[i-1]>=A[i]);
            p2=p2&(A[i-1]<=A[i]);
        }
    return p1||p2;}
//https://leetcode.com/problems/sort-array-by-parity-ii/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> sortArrayByParityII(vector<int>& A){
        int j=1;    
        for(int i=0;i<A.size();i+=2){
            if(A[i]&1){
                while(A[j]&1){
                    j=j+2;
                }
                swap(A[i],A[j]);
            }
        }
        
    return A;}

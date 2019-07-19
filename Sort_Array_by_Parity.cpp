//https://leetcode.com/problems/sort-array-by-parity/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool compare(int a,int b){
    return (a%2==0 && b&1);
}
vector<int> sortArrayByParity(vector<int> &A)
{
    sort(A.begin(),A.end(),compare);
    return A;
}
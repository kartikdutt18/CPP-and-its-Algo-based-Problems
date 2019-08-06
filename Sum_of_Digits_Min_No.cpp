//https://leetcode.com/problems/sum-of-digits-in-the-minimum-number/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int sumOfDigits(vector<int> &A)
{
    int mins=INT_MAX;
    for(auto i: A) mins=min(i,mins);
    int sum=0;
    while(mins){
        sum+=mins%10;
        mins/=10;
    }
    return sum&1?0:1;
}
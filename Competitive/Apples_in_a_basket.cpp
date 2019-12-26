// https://leetcode.com/problems/how-many-apples-can-you-put-into-the-basket/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxNumberOfApples(vector<int> &arr)
{
    sort(arr.begin(),arr.end());
    int cnt=0;
    int max_wt=5000;
    int j=0;
    while (j < arr.size() && max_wt - arr[j] >= 0)
    {
        cnt++;
        max_wt-=arr[j++];
    }
    return cnt;
}
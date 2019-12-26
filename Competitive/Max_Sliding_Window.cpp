//https://leetcode.com/problems/sliding-window-maximum/submissions/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &A, int k)
    {
        vector<int> ans;
        deque<int> dq;
        for (int i = 0; i < A.size(); i++)
        {
            if (!dq.empty() && i - dq.front() == k)
                dq.pop_front();
            while (!dq.empty() && A[i] > A[dq.back()])
                dq.pop_back();
            dq.emplace_back(i);
            if (i - k + 1 >= 0)
                ans.push_back(A[dq.front()]);
        }

        return ans;
    }
};
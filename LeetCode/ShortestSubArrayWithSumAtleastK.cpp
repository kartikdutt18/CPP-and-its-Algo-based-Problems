#include<iostream>
#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& A, int K)
    {
        vector<long> prefixSum(A.size() + 1, 0);
        for (int i = 1; i <= A.size(); i++)
        {
            prefixSum[i] = prefixSum[i  - 1] + (long) A[i - 1];
        }
        
        deque<int> dq;
        int ans = INT_MAX;
        for (int i = 0; i < prefixSum.size(); i++)
        {
            while (!dq.empty() && prefixSum[i] <= prefixSum[dq.back()])
                dq.pop_back();
            while (!dq.empty() && prefixSum[i] - prefixSum[dq.front()] >= K)
            {
                ans = min(i - dq.front(), ans);
                dq.pop_front();
            }
    
            dq.push_back(i);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

int main()
{
  ios::sync_with_stdio(false);
  return 0;
}
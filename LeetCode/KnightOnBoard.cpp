#include<iostream>
#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

class Solution {
public:

    double knightProbability(int N, int K, int r, int c)
    {
       // 3D DP.
       vector<vector<vector<double>>> dp(2, vector<vector<double>>(N, vector<double>(N, 0.0)));
       dp[0][r][c] = 1.0;

        vector<int> dx = {2, 2, 1, 1, -1, -1, -2, -2};
        vector<int> dy = {1, -1, 2, -2, 2, -2, 1, -1};
       // If no moves always on board.
       for (int k = 0; k < K; k++)
       {
           for (int x = 0; x < N; x++)
           {
               for (int y = 0; y < N; y++)
               {
                   for (int idx = 0; idx < dx.size(); idx++)
                   {
                       int xhat = x + dx[idx];
                       int yhat = y + dy[idx];
                       if (xhat >= 0 && yhat >= 0 && xhat < N && yhat < N)
                       {
                           dp[1][xhat][yhat] += dp[0][x][y] / 8.0;
                       }
                   }
               }
           }
           swap(dp[0], dp[1]);
           dp[1] = vector<vector<double>>(N, vector<double>(N, 0.0));
       }

        double ans = 0.0;
        for (int x = 0; x < N; x++)
        {
            for (int y = 0; y < N; y++)
            {
                ans += dp[0][x][y];
            }
        }

        return ans;
    }
};

int main()
{
  ios::sync_with_stdio(false);
  return 0;
}
#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
  int n;
  cin>>n;
  vector<vector<int>> dp(n, vector<int>(n));
  int diagSum = 0;
  int gRows = 0;
  for(int i = 0; i < n; i++)
  {set<int> ht;
    for(int j = 0; j < n; j++)
    {
      cin>>dp[i][j];
      diagSum+= (i==j)*dp[i][j];
      ht.insert(dp[i][j]);
    }
    gRows+=(ht.size()!=n);
  }
  int gCols = 0;
  for(int i = 0; i < n; i++)
  {set<int> ht;
    for(int j = 0; j < n; j++)
    {
      ht.insert(dp[j][i]);
    }
    gCols+=(ht.size()!=n);
  }
  cout<<diagSum<<" "<<gRows<<" "<<gCols<<endl;
}
int main() {

  int t;
  cin>>t;
  for(int i = 1; i <= t; i++)
  {
    cout << "Case #" << i <<": ";
    solve();
  }
  return 0;
}
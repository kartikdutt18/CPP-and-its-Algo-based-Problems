#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(vector<int> b, int money)
{
  int i = 0;
  int ans=0;
  sort(b.begin(), b.end());
  while(i<b.size() && money>0)
  {
    if(money>=b[i])
    {
      ans++;
      money-=b[i];
    }
    i++;
  }
  cout<<ans<<endl;
}
int main() {
int t;
cin>>t;
for(int i = 1; i<=t; i++)
{
  cout<<"Case #"<<i<<": ";
  int n,m;
  cin>>n>>m;
  vector<int>a(n);
  for(int j=0;j<n;j++)
  {
    cin>>a[j];
  }
  solve(a, m);
}
return 0;
}
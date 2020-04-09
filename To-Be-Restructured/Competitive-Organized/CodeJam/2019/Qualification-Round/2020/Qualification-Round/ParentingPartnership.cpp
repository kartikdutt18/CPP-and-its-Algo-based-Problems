#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
  int n;
  cin>>n;
  vector<tuple<int,int, int>> v(n);
  string s(n, 'X');
  for(int i = 0; i<n; i++)
  {
    cin>>get<0>(v[i]) >> get<1>(v[i]);
    get<2>(v[i]) = i;
  }
  vector<tuple<int,int,int>> C;
  vector<tuple<int,int, int>> J;
  sort(v.begin(), v.end());
  for(auto i:v)
  {
    if(C.empty() || (get<1>(C.back()) <= get<0>(i)))
    {
      s[get<2>(i)]='C';
      C.push_back(i);
    }
    else if (J.empty() || (get<1>(J.back()) <= get<0>(i)))
    {
      s[get<2>(i)]='J';
      J.push_back(i);
    }
    else
    {
      s = "IMPOSSIBLE";
      break;
    }
  }
  cout << s << endl;
}

int main() {
  int t;
  cin>>t;
  for (int i = 1; i <= t; i++)
  {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
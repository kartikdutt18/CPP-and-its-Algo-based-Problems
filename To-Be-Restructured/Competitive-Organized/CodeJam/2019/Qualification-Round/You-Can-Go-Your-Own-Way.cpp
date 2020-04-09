#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
  int n;
  cin>>n;
  string s = "";
  while(s.length()==0)
    getline(cin, s);
  string ans = "";
  for(int i = 0; i<s.length();i++)
  {
    char ch = s[i];
    ans += ch=='E'?'S':'E';
  }
  cout << ans << endl;
  return;
}

int main() {

int t;
cin>>t;
for(int i = 0; i < t; i++)
{
  cout<<"Case #"<<i+1<<": ";
  solve();
}
return 0;
}
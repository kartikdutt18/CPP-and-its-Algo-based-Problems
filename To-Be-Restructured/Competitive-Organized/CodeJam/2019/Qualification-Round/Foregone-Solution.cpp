#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

void Solve(string s)
{
  string s1,s2;
  for(int i = 0; i<s.length();i++)
  {
    s1.push_back(s[i]!='4'?s[i]:'3');
    if(s2.length()==0 && s[i]=='4')
      s2.push_back('1');
    else if(s2.length() != 0)
    {
      s2.push_back(s[i] != '4' ? '0' : '1');
    }
  }
  if(s2.length() == 0)
    s2 = "0";
  cout << s1 << " " <<s2<<endl;
}
int main() {
int t;
cin>>t;
for(int i = 1;i<=t; i++)
{
  string s;
  while(s.length()==0)
  getline(cin, s);
  cout<<"Case #"<<i<<": ";
  Solve(s);
}
return 0;
}
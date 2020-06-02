#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

void GetString(string& s)
{
  while(s.length() == 0)
    getline(cin, s);
}

void MakeFreq(vector<int>&v, string s, int mult = 1)
{
  for(char ch : s)
    v[ch - 'A'] = v[ch - 'A'] + mult;
}
int main()
{
  string s1, s2, s3;
  GetString(s1);
  GetString(s2);
  GetString(s3);
  vector<int> v(26, 0);
  MakeFreq(v, s1, 1);
  MakeFreq(v, s2, 1);
  MakeFreq(v, s3, -1);
  if (v == vector<int>(26, 0))
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
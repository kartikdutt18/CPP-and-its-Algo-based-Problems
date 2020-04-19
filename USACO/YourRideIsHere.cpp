/*
ID: kartikd1
PROG: ride
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll GetValue(string s)
{
  ll ans=1;
  for(char ch : s)
    ans = (ans*((ch - 'A')+1))%47;
  ans %=47;
  return ans;
}
int main()
{
  ofstream fout("ride.out");
  ifstream fin("ride.in");
  string s1, s2;
  while(s1.length() == 0)
    getline(fin, s1);
  while(s2.length() == 0)
    getline(fin, s2);
  if (GetValue(s1) == GetValue(s2))
    fout << "GO\n";
  else
  {
    fout << "STAY\n";
  }
  return 0;
}
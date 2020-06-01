#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  string s1, s2;
  while(s1.empty())
    getline(cin, s1);
  while(s2.empty())
    getline(cin, s2);

  for(int i = 0; i < s1.length(); i++)
  {
    if (s1[i] != s2[i])
      cout << 1;
    else
    {
      cout << 0;
    }
  }
  cout << endl;
  return 0;
}
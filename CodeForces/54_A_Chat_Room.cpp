#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  string s = "";
  while(s.length() == 0)
    getline(cin, s);
  string desired = "hello";
  int j = desired.length() - 1;
  bool flag = false;
  for (int i = s.length() - 1; i>=0 && j >= 0; i--)
  {
    if (s[i] == desired[j])
      j--;
  }
  if (j<0)
    cout << "YES\n";
  else
  {
      cout << "NO\n";
  }
  
  return 0;
}
#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  string s;
  while(s.length() == 0)
    getline(cin, s);
  if (islower(s[0]))
    s[0] = toupper(s[0]);
  cout << s << endl;
  return 0;
}
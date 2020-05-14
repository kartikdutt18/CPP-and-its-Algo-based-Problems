#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  int t = 0;
  int x = 0;
  cin >> t;
  while(t--)
  {
    string s = "";
    while (s.length() == 0)
      getline(cin, s);
    if (s[0] == '+' or s.back() == '+')
      x++;
    else
      x--;
  }
  cout << x << endl;
  return 0;
}
#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  int maxOnes = 0;
  int maxZeros = 0;
  string s;
  while(s.length() == 0)
    getline(cin, s);
  int curOnes = 0;
  int curZeros = 0;
  for(int i = 0; i < s.length(); i++)
  {
    if (s[i] == '0')
    {
      curZeros++;
      maxOnes = max(maxOnes, curOnes);
      maxZeros = max(maxZeros, curZeros);
      curOnes = 0;
    }
    else
    {
      curOnes++;
      maxOnes = max(maxOnes, curOnes);
      maxZeros = max(maxZeros, curZeros);
      curZeros = 0;
    }
  }
  if (maxOnes >= 7 || maxZeros >= 7)
    cout << "YES\n";
  else
  {
    cout << "NO\n";
  }
  
  return 0;
}
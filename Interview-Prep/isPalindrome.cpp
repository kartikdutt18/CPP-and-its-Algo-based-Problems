#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

// Solution 1 : O(N) / O(N)
// Simpler to write.
bool isPalindrome(string s)
{
  string temp = s;
  reverse(s.begin(), s.end());

  return s == temp;
}

// Solution 2: O(N) / O(1).
bool isPalindrome2(string str)
{
  int i = 0, j = str.size() - 1;
  while (i <= j)
  {
    if (str[i] != str[j])
      return false;
    i++;
    j--;
  }
  return true;
}

int main()
{
  cout<<isPalindrome("stts")<<endl;
  return 0;
}
#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Solution
{
public:
  int toInt(char c)
  {
    return c - '0';
  }
  // O(n) / O(1)
  // 7 minutes.
  // No addition operator.
  string addBinary(string a, string b)
  {
    if (b.length() > a.length())
      return addBinary(b, a);
    b = string(a.length() - b.length(), '0') + b;
    int carry = 0;
    for (int j = a.length() - 1; j >= 0; j--)
    {
      int prev = toInt(a[j]);
      a[j] = (toInt(a[j]) ^ toInt(b[j]) ^ carry) + '0';
      carry = (prev & toInt(b[j]) || carry & (prev ^ toInt(b[j])));
    }
    if (carry)
      a = "1" + a;
    return a;
  }
};

int main() {

  return 0;
}
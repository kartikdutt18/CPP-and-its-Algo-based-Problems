#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int isPalindrome(int A)
{
  if (A < 0)
    return 0;
  int num = 0;
  int temp = A;
  while (temp)
  {
    num = num * 10 + (temp % 10);
    temp = temp / 10;
  }
  return num == A;
}

int main()
{
  return 0;
}
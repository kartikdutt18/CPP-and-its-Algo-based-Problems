#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  int n;
  cin >> n;
  ll curSum = 0;
  ll maxSum = 0;
  while(n--)
  {
    int a, b;
    cin >> a >> b;
    curSum -=a;
    curSum += b;
    maxSum = maxSum < curSum ? curSum : maxSum;
  }
  cout << maxSum << endl;
  return 0;
}
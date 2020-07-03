#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  int val = 0;
  vector<int> A = {1, 1, 3, 3, 4, 4, 2};
  for (int num : A)
    val = val ^ num;
  cout << val << endl;
  return 0;
}
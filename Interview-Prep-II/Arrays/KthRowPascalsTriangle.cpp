#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> getRow(int A)
{

  vector<int> v;
  v.push_back(1);
  for (int i = 1; i <= A; i++)
  {
    v.push_back(v.back() * (long long)(A - i + 1) / (i));
  }
  return v;
}


int main() {
return 0;
}
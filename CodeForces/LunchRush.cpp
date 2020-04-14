#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  int n, k;
  cin>>n>>k;
  int maxJoy = INT_MIN;
  for(int i=0; i < n; i++)
  {
    int f,t;
    cin>>f>>t;
    maxJoy = max(maxJoy, f - max(0, t - k));
  }
  cout << maxJoy << endl;
  return 0;
}
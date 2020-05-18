#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<ll> v(m, 0);
  for(int i = 0; i < m; i++)
    cin>>v[i];
  ll curHouse = 1;
  ll steps = 0;
  for(int i : v)
  {
    //cout << i << " " << steps << " " << curHouse << endl;
    if (i < curHouse)
      steps += n - curHouse + i;
    else
      steps += i - curHouse;
    curHouse = i;
  }
  cout << steps << endl;
  return 0;
}
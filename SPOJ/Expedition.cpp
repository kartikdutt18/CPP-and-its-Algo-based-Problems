#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(vector<pair<ll, ll>> fuelStops)
{
  int i = 0;

  int Finstops = 0;
  while (i < fuelStops.size() - 1)
  {
    if(fuelStops[i].first - fuelStops[i + 1].first > fuelStops[i].second)
    {
      cout << - 1 << endl;
      return;
    }

    int j = i + 1;
    while(fuelStops[i].first - fuelStops[j].first < fuelStops[i].second)
    {
      j++;
    }
    Finstops++;
    fuelStops[j].second += fuelStops[i].second - (fuelStops[i].first - fuelStops[j].first);
    i = j;
  }
  cout << Finstops - 1 << endl;
  return;
}

int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> stops(n + 2, {0, 0});
    for(int i = 1; i <= n; i++)
    {
      cin >> stops[i].first >> stops[i].second;
    }
    cin>>stops[0].first >> stops[0].second;
    sort(stops.begin(), stops.end());
    reverse(stops.begin(), stops.end());
    solve(stops);
  }
  return 0;
}
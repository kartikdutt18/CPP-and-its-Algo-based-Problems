#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> sieve(1000000 + 1, 1);
void isPrime()
{
  for (int i = 2; i*i <= 1000000; i++)
  {
    if (sieve[i])
    {
      for (int j = i * i; j <= 1000000; j+=i)
        sieve[j] = 0;
    }
  }
}

void solve(ll n)
{
  if (floor(sqrt(n)) == sqrt(n) && sieve[floor(sqrt(n))] && n > 2)
    cout << "YES\n";
  else
    cout << "NO\n";
}
int main()
{
  int n;
  cin >> n;
  isPrime();
  vector<ll> v(n);
  for(int i = 0; i < n; i++)
  {
    cin >> v[i];
    solve(v[i]);
  }
  return 0;
}
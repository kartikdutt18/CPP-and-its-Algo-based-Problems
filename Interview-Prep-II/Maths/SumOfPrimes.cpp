#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> GeneratePrime(int A)
{
  vector<int> v(A + 1, 1);
  for (int i = 2; i * i <= A; i++)
  {
    if (v[i])
    {
      for (int j = i * i; j <= A; j += i)
        v[j] = false;
    }
  }

  return v;
}
bool isPrime(int A)
{
  if (A == 2)
    return true;
  for (int i = 2; i * i <= A; i++)
  {
    if (A % i == 0)
      return false;
  }
  return true;
}
vector<int> primesum(int A)
{
  if (A <= 2)
    return {-1};
  if (A == 4)
    return {2, 2};
  for (int i = 2; i < A; i++)
  {
    if (isPrime(i) && isPrime(A - i))
    {
      vector<int> ans = {i, A - i};
      sort(ans.begin(), ans.end());
      return ans;
    }
  }
  return {-1};
}

vector<int> Helper(int A)
{
  if (A <= 2)
    return {-1};
  if (A == 4)
    return {2, 2};
  vector<int> primes = GeneratePrime(A);
  for (int i = 2; i < primes.size(); i++)
  {
    if (primes[i] && primes[A - i] && A - i > 1)
    {
      vector<int> ans = {i, A - i};
      sort(ans.begin(), ans.end());
      return ans;
    }
  }
}
int main()
{
  return 0;
}
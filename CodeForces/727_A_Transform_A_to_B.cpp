#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

void dfs(ll a, ll b, set<ll>& ht, vector<ll> nums)
{
  if (a == b)
  {
    cout << "YES\n";
    cout << nums.size() + 1 << endl;
    for (int num : nums)
      cout << num << " ";
    cout << b << endl;
  }
  if (ht.count(a))
    return;
  ht.insert(a);
  nums.push_back(a);
  if (2*a <= b && !ht.count(2*a))
    dfs(2*a, b, ht, nums);
  if (10 * a + 1 <= b && !ht.count(10*a + 1))
    dfs(10*a+1, b, ht, nums);
  return;
}
void solve()
{
  // a < b;
  ll a, b;
  cin >> a >> b;
  set<ll> ht;
  dfs(a, b, ht, vector<ll>());
  if (!ht.count(b))
    cout << "NO\n";
  return;
}

void fastSolve()
{
  // a < b;
  ll a, b;
  cin >> a >> b;
  deque<ll> nums;
  while(b>a)
  {
    nums.push_front(b);
    if ((b-1)%10 == 0)
    {
      b = (b - 1) / 10;
    }
    else if (b % 2 ==0)
    {
      b=b/2;
    }
    else
    {
      break;
    }
    
  }
  if (b == a)
  {
    nums.push_front(a);
    cout << "YES\n";
    cout << nums.size() << endl;
    for (int num : nums)
      cout << num << " ";
  }
  else
  {
    cout << "NO\n";
  }
  return;
}

int main() {
  //solve();
  fastSolve();
  return 0;
}
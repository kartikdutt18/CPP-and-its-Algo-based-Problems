#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

void print(string text, vector<int> v)
{
  cout << text << " : \t";
  for (int i = 0; i < v.size(); i++)
    cout << v[i] << ", ";
  cout << endl;
}

void sorted(vector<int>& v)
{
  int first3 = v.size() - 1, last0 = 0;
  int i = 0;
  while (i <= first3)
  {
    if (v[i] == 0)
    {
      swap(v[i], v[last0]);
      last0++;
      i++;
    }
    else if (v[i] == 3)
    {
      swap(v[i], v[first3]);
      first3--;
    }
    else
      i++;
  }

  int start = last0;
  i = start;
  while (i <= first3)
  {
    if (v[i] == 1)
    {
      swap(v[i], v[last0]);
      last0++;
      i++;
    }
    else if (v[i] == 2)
    {
      swap(v[i], v[first3]);
      first3--;
    }
  }
}

int main()
{
  int t = 100;
  while (t--)
  {
    int n = rand() % 10;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
      v[i] = rand() % 4;
    vector<int> ans = v;
    vector<int> input = v;
    sort(ans.begin(), ans.end());
    sorted(v);
    if (v != ans)
    {
      cout << "Doesn't work!" << std::endl;
      print("input", input);
      print("output", v);
      print("ans", ans);
    }
    else
    {
      cout << "Passed :" << 100 - t << endl;
    }
    
  }

  return 0;
}
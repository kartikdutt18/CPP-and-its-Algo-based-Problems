#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<string> fizzBuzz(int A)
{
  vector<string> ans;
  for (int i = 1; i <= A; i++)
  {
    if (i % 3 == 0 && i % 5 == 0)
    {
      ans.push_back("FizzBuzz");
    }
    else if (i % 5 == 0)
    {
      ans.push_back("Buzz");
    }
    else if (i % 3 == 0)
    {
      ans.push_back("Fizz");
    }
    else
    {
      ans.push_back(to_string(i));
    }
  }
  return ans;
}

int main()
{
  return 0;
}
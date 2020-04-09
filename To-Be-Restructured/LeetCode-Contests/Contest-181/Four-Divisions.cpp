#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Solution
{
  public:
  bool divisor(int n)
  {
    int cnt = 0;
    int sum=0;
    for(int i = 1; i <= sqrt(n); i++)
    {
      cnt+=(n%i)==0;
      sum=((n%i)==0)?n/i:0;
    }
    return cnt==4?sum:0;
  }
  int sumFourDivisors(vector<int>& nums) {
    int ans=0;
    for(auto i:nums)
      ans+=divisor(i);
    return ans;
  }
};
int main() {

return 0;
}
//https://leetcode.com/contest/biweekly-contest-19/problems/number-of-steps-to-reduce-a-number-to-zero/
#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int numberOfSteps(int num)
{
  int steps = 0;
  while (num)
  {
    if (num % 2 == 0)
      num /= 2;
    else
      num--;
    steps++;
  }
  return steps;
}

int main() {

return 0;
}
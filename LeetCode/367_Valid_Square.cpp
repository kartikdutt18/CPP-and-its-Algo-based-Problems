#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

// O(n) / O(1).
bool isValidSqaureLinear(int num)
{
  for (long long i = 1; i <= num / 2; i++)
    if (i * i == num)
      return true;
  return false || num == 1;
}

// Binary Search : O(logn) / O(1)
bool isValidSquare(int num)
{
  int low = 1;
  int high = num;
  while(low <= high)
  {
    long long mid = low + (-low + high) / 2;
    if (mid * mid == num)
      return true;
    if (mid * mid < num)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return false || num == 1;
}

// Newtons methods : O(logn) / O(1)
bool isValidNewtonsMethods(int num)
{
  long long x0 = num/2 + 1, x1 = num/2 + 1; // Set Starting points.
  // Adding 1 to avoid division by zero for 1.
  // F(x) = num - x*x
  // F'(x) = -2(x)
  // x1 = X - F(x) / F'(x)
  do
  {
    x0 = x1;
    x1 = (num - x0 * x0) / (2 * x0);
    if (x1 * x1 == num)
      return true;
  } while (abs(x0 - x1) > 1);
  return false;
}
int main()
{

  return 0;
}
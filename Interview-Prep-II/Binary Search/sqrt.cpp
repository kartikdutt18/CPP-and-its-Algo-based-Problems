#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int A;
    cin >> A;
    int low = 0;
    int high = A;
    while (low <= high)
    {
      long long mid = (low + high) / 2;
      if (mid * mid == A)
        return mid;
      if (mid * mid > A)
        high = mid - 1;
      else
        low = mid + 1;
    }
    cout << min(low, high) << endl;
  return 0;
}
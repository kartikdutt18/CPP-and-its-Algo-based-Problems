#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

unsigned int reverseBits(unsigned int num)
{
  unsigned int NO_OF_BITS = sizeof(num) * 8;
  unsigned int reverse_num = 0, i, temp;

  for (i = 0; i < NO_OF_BITS; i++)
  {
    temp = (num & (1 << i));
    if (temp)
      reverse_num |= (1 << ((NO_OF_BITS - 1) - i));
  }
  cout << "Brute Force: " << reverse_num << endl;
  return reverse_num;
}

void solve(unsigned int x)
{
  unsigned int len = sizeof(x) * 8;
  unsigned int totalXor = (x >> (len / 2)) ^ x;
  cout << totalXor << endl;
  x = ((((x >> (len / 2)) ^ totalXor) << (len / 2)) | (x ^ totalXor));
  cout << "O(1) : " << x << endl << "---------\n";
  return;
}

int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int x;
    cin>>x;
    reverseBits(x);
    solve(x);
  }
  return 0;
}
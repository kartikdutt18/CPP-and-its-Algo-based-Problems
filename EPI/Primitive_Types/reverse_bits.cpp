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
  return reverse_num;
}

unordered_map<int, int> ht;
void reverseBitsFast(unsigned int num)
{
  if (ht.empty())
  {
    for (int i = 0; i < 16; i++)
    {
      ht[i] = reverseBits(i);
    }

  }

  const int bitMask = 0xFFFF;
  const int wordSize = 16;
  unsigned int NO_OF_BITS = sizeof(num) * 8;
  int ans = 0;
  int numBlocks = NO_OF_BITS / wordSize;
  for (int i = 0; i < numBlocks; i++)
  {
    ans = ans | (ht[(num >> (i * wordSize)) & bitMask] << ((numBlocks - i - 1) * wordSize));
  }
  cout << ans << endl;
}

int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int x;
    cin>>x;
    cout << reverseBits(x) << endl;
    reverseBitsFast(x);
  }
  return 0;
}
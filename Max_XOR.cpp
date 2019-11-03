//CB: XOR Profit Problem

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int l, r;
    cin >> l >> r;
    int msb = 0;
    int xor_limit = l ^ r;
    while (xor_limit)
    {
        msb++;
        xor_limit >>= 1;
    }
    int max_xor = 0;
    int pow = 1;
    while (msb--)
    {
        max_xor += pow;
        pow <<= 1;
    }
    cout << max_xor << endl;
    return 0;
}
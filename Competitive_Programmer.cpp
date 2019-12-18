//https://codeforces.com/contest/1266/problem/A
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        while (s.length() == 0)
            getline(cin, s);
        long long int twoCount = 0;
        long long int threeSum = 0;
        long long int zeroCount = 0;
        for (auto j : s)
        {
            if ((j - '0') % 2 == 0 && j != '0')
                twoCount++;
            if (j - '0' == 0)
                zeroCount++;
            threeSum += (j - '0');
        }
        if (threeSum % 3 == 0 && ((twoCount > 0 && zeroCount > 0) || (zeroCount > 1)))
            cout << "red" << endl;
        else
            cout << "cyan" << endl;
    }
    return 0;
}
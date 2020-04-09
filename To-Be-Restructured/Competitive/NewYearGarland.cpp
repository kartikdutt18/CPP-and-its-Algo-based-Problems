//
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long r, g, b;
        cin >> r >> g >> b;

        long long triplet = min(r, min(g, b));
        r -= triplet;
        g -= triplet;
        b -= triplet;
        if ((abs(r - b) <= 1 && g == 0) || (abs(g - b) <= 1 && r == 0) || (abs(r - g) <= 1 && b == 0))
        {
            cout << "YES \n";
        }
        else
        {
            cout << "NO \n";
        }
    }

    return 0;
}

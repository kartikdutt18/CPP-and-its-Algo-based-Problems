//https://codeforces.com/contest/1278/problem/A
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void checkPassword(string p, string h)
{
    vector<int> pH(27, 0);
    vector<int> hH(27, 0);
    for (auto i : p)
        pH[i - 'a']++;
    bool ans = false;
    int prev = 0;
    for (int i = 0; i < h.length(); i++)
    {
        hH[h[i] - 'a']++;
        if (i >= p.length())
        {
            hH[h[prev] - 'a']--;
            prev++;
        }
        if (hH == pH)
        {
            ans = true;
            break;
        }
    }
    if (hH == pH)
        ans = true;
    if (ans == true)
        cout << "YES \n";
    else
        cout << "NO \n";
    return;
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string h, p;
        while (p.length() == 0)
            getline(cin, p);
        while (h.length() == 0)
            getline(cin, h);
        checkPassword(p, h);
    }
    return 0;
}
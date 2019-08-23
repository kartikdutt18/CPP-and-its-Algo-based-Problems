
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void recur_count(string s, int i, int &count, int inc)
{
    if (i >= s.length())
        return;
    if (s.substr(i, 3) == "aaa")
    {
        count++;
    }
    recur_count(s, i + inc, count, inc);
}
int main()
{
    string s = "";
    while (s.length() == 0)
        getline(cin, s);
    int t = 0;
    recur_count(s, 0, t, 1);
    cout << t << endl;
    t = 0;
    recur_count(s, 0, t, 3);
    cout << t << endl;
    return 0;
}
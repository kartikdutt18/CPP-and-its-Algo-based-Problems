//CB: Unlock
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string unlock(string s, long long k)
{
    map<char, int> ht;
    string max_string = s;
    sort(max_string.begin(), max_string.end(), greater<char>());
    int n = s.length(), len = s.length();
    for (int i = 0; i < len; i++)
    {
        ht[s[i]] = i;
    }
    int i = 0;
    while (i < len && s != max_string && k > 0)
    {
        if (s[i] - '0' != n - i)
        {
            char t = s[i];
            s[i] = n - i + '0';
            s[ht[n - i + '0']] = t;
            ht[t] = ht[n - i + '0'];
            ht[s[i]] = i;
            k--;
        }
        i++;
    }
    return s;
}
int main()
{
    string s;
    long long n, k;
    cin >> n >> k;

    s = "";
    for (int i = 0; i < n; i++)
    {
        string s1;
        cin >> s1;
        s += s1;
    }

    if (k < n)
    {
        s = unlock(s, k);
        for (int i = 0; i < n; i++)
        {
            cout << s[i] << " ";
        }
    }
    else
    {
        sort(s.begin(), s.end(), greater<char>());
        cout << s << endl;
    }
    return 0;
}
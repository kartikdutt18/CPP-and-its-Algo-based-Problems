//CB: String Window
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void string_window(string s1, string s2)
{
    if (s2.length() == 0)
        return;
    if (s1.length() == 0 || s1.length() < s2.length())
    {
        cout << "No string";
        return;
    }
    vector<int> f_s2(256, 0);
    vector<int> f_s1(256, 0);
    int count = 0;
    int start = 0;
    int start_ind = -1;
    int len = INT_MAX;
    for (auto i : s2)
        f_s2[i]++;

    for (int i = 0; i < s1.length(); i++)
    {
        f_s1[s1[i]]++;
        if (f_s2[s1[i]] != 0 && f_s2[s1[i]] >= f_s1[s1[i]])
            count++;
        if (count == s2.length())
        {
            while (f_s1[s1[start]] == 0 || f_s1[s1[start]] > f_s2[s1[start]])
            {
                if (f_s1[s1[start]] > f_s2[s1[start]])
                    f_s1[s1[start]]--;
                start++;
            }
            if (len > i - start + 1)
            {
                len = i - start + 1;
                start_ind = start;
            }
        }
    }

    if (start_ind == -1)
    {
        cout << "No string";
        return;
    }
    cout << s1.substr(start_ind, len);
    return;
}

int main()
{
    string s, t;
    getline(cin, s);
    getline(cin, t);
    string_window(s, t);
    cout << endl;
    return 0;
}
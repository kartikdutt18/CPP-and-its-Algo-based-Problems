#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void string_window(string s, string t)
{
    vector<int> end_pts;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == t.back())
            end_pts.emplace_back(i);
    int min_len = INT_MAX;
    int start_index = 0;
    for (auto i : end_pts)
    {
        int j = t.length() - 1;
        int k = i;
        while (j >= 0 && k >= 0)
        {
            if (s[k] == t[j])
            {
                j--;
            }
            k--;
        }

        if (j < 0 && (i - k + 1) < min_len)
        {
            min_len = min(min_len, i - k);
            start_index = k + 1;
        }
    }
    //cout<<"Min_len "<<min_len<<" Start from "<<start_index<<endl;
    if (min_len == INT_MAX)
        cout << "No string" << endl;
    else
        cout << s.substr(start_index, min_len) << endl;
    return;
}
int main()
{
    string s, t;
    getline(cin, s);
    getline(cin, t);
    string_window(s, t);
    return 0;
}

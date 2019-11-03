#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        stack<int> st;
        vector<int> remove;
        string ans = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                st.push(i);
            }
            else if (s[i] == ')')
            {
                if (!st.empty())
                    st.pop();
                else
                    remove.push_back(i);
            }
        }
        while (!st.empty())
        {
            remove.push_back(st.top());
            st.pop();
        }
        sort(remove.begin(), remove.end());
        int j = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (j < remove.size() && i == remove[j])
            {
                j++;
                continue;
            }
            else
            {
                ans += s[i];
            }
        }
        return ans;
    }
};
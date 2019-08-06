//
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
map<char, int> ht;
bool compare(char a, char b)
{
    if (ht[a] != ht[b])
        return ht[a] > ht[b];
    else
        return a > b;
}
string frequencySort(string s)
    {
        for (auto i : s)
        {
            ht[i] = ht[i] + 1;
        }
        sort(s.begin(), s.end(), compare);
        ht.clear();
        
        return s;
}

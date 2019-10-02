//CTCI 1.3
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string URLify(string s1){
    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] == ' ' && i != 0)
        {
            s1 = s1.substr(0, i) + "%20" + s1.substr(i + 1, s1.length() - i);
        }
    }
    return s1;
}
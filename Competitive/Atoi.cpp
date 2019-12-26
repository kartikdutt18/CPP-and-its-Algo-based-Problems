//https://leetcode.com/problems/string-to-integer-atoi/submissions/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int myAtoi(string str)
{
    stringstream s(str);
    vector<string> res;
    while (s.good())
    {
        string ss;
        s >> ss;
        res.emplace_back(ss);
    }
    int mult = 1;
    while (res[0][0] == '-' || res[0][0] == '+')
    {
        mult *= res[0][0] == '-' ? -1 : 1;
        res[0] = res[0].substr(1);
    }
    if (res[0].size() == 0 || res[0][0] - '0' < 0 || res[0][0] - '9' > 0)
        return 0;
    if (mult == -1)
        res[0] = "-" + res[0];
    int x;
    stringstream ss(res[0]);
    ss >> x;
    return x;
}

//SOlUTION THAT GETS ACCEPTED BUT MAKES LESSER SENSE AS +- =- AND NOT INVALID
int myAtoi(string str)
{
    stringstream s(str);
    vector<string> res;
    while (s.good())
    {
        string ss;
        s >> ss;
        res.emplace_back(ss);
    }
    int mult = 0;
    if (res[0][0] == '-')
    {
        res[0] = res[0].substr(1);
        mult = 1;
    }

    else if (res[0][0] == '+')
        res[0] = res[0].substr(1);
    //while(res[0][0]=='+' || res[0][0]=='-') res[0]=res[0].substr(1);
    if (res[0].size() == 0 || res[0][0] - '0' < 0 || res[0][0] - '9' > 0)
        return 0;
    if (mult)
        res[0] = "-" + res[0];
    int x;
    stringstream ss(res[0]);
    ss >> x;
    return x;
}
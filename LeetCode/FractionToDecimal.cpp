#include<iostream>
#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator)
    {
       if (denominator == 0)
           return to_string(INT_MAX);
        if (numerator == 0)
            return "0";

        string ans = "";
        if (numerator < 0 ^ denominator < 0)
            ans += "-";

        long dividend = abs(numerator);
        long divisor = abs(denominator); 
        
        ans += to_string(dividend / divisor);
        long remainder = dividend % divisor;
        if (remainder == 0)
        {
            return ans;
        }
        
        ans += ".";
        unordered_map<long, int> ht;
        while (remainder)
        {
            if (ht.count(remainder))
            {
                ans = ans.substr(0, ht[remainder]) + "(" + ans.substr(ht[remainder]);
                ans += ")";
                break;
            }
            ht.insert({remainder, ans.length()});
            remainder *= 10;
            ans = ans + to_string(remainder / divisor);
            remainder %= divisor;
        }

        return ans;
    }
};

int main()
{
  ios::sync_with_stdio(false);
  return 0;
}
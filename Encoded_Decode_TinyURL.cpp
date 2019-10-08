//https://leetcode.com/problems/encode-and-decode-tinyurl/submissions/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    long long int cnt;
    map<string, string> short_to_long;

public:
    Solution(int x = 0) : cnt(x) {}
    // Encodes a URL to a shortened URL.
    string base62(long long int cnt)
    {
        string s = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string hash_str = "";
        while (cnt > 0)
        {
            hash_str = s[cnt % 62] + hash_str;
            cnt /= 62;
        }
        return hash_str;
    }
    string encode(string longUrl)
    {
        cnt++;
        string hashed_str = "http://tinyurl.com/" + base62(cnt);
        short_to_long[hashed_str] = longUrl;
        return hashed_str;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        if (short_to_long.count(shortUrl))
            return short_to_long[shortUrl];
        return shortUrl;
    }
};
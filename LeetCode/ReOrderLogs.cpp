#include<iostream>
#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs)
    {
        vector<string>::iterator it = stable_partition(logs.begin(), logs.end(), [](const string& str) {
            return isalpha(str[str.find(' ') + 1]);
            });

        // Sort letter-logs: We're only iterating on letter-logs in this case.
        // We're creating a substring for every element we compare that doesn't include the identifier
        // If the logs are the same except the identifier, we compare the strings, otherwise, the substrings

        sort(logs.begin(), it, [](const string& str1, const string& str2) {
            auto substr1 = string(str1.begin() + str1.find(' '), str1.end());
            auto substr2 = string(str2.begin() + str2.find(' '), str2.end());
            return (substr1 == substr2) ? str1 < str2 : substr1 < substr2;
            });

        return logs;
    }
};

int main()
{
  ios::sync_with_stdio(false);
  return 0;
}
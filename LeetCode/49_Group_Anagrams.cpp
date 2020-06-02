#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> ht;
        for(auto str:strs)
        {
            vector<int> freqArr(26,0);
            for(auto i:str) freqArr[i-'a']++;
            if(ht.count(freqArr))
            {
                ht[freqArr].push_back(str);
            }
            else
            {
                vector<string> temp;
                temp.push_back(str);
                ht.insert({freqArr,temp});
            }
        }
        vector<vector<string>> ans;
        for(auto i:ht)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};

int main()
{
  return 0;
}
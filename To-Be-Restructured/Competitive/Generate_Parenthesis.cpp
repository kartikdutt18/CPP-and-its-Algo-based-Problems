//https://leetcode.com/problems/generate-parentheses/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<string> ans;
void Generate_Combinations(int n, int open, int closed, string cur_set)
{
    if (cur_set.length() == 2 * n && open == closed)
    {
        ans.push_back(cur_set);
        return;
    }

    if (open <= n)
    {
        cur_set.push_back('(');
        Generate_Combinations(n, open + 1, closed, cur_set);
        cur_set.pop_back();
    }
    if (closed < n && open > closed)
    {
        cur_set.push_back(')');
        Generate_Combinations(n, open, closed + 1, cur_set);
        cur_set.pop_back();
    }
    return;
}
vector<string> generateParenthesis(int n)
{
    Generate_Combinations(n, 0, 0, "");
    return ans;
}

/*vector<string> generateParenthesis(int n)
{
    if(n<=0) return {};
    vector<vector<string>> dp(n+2);
    vector<string> temp={"()"};
    dp[1]=temp;
    for(int i=2;i<=n;i++){
        set<string> s;
        for(auto j:dp[i-1]){
            s.insert("("+j+")");
            s.insert("()"+j);
            s.insert(j+"()");
        }
        for(auto j:s){
            dp[i].push_back(j);
        }
    }
    return dp[n];
}
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string toHexspeak(string num)
    {
        stringstream ss;
        stringstream ss1(num);

        set<char> dict = {'A', 'B', 'C', 'D', 'E', 'F', 'I', 'O'};
        long long n;
        ss1 >> n;
        ss << hex << n;
        string res = ss.str();
        std::for_each(res.begin(), res.end(), [](char &c) {
            c = ::toupper(c);
        });

        for (int i = 0; i < res.length(); i++)
        {
            if (res[i] == '0')
                res[i] = 'O';
            else if (res[i] == '1')
                res[i] = 'I';
            else if (dict.count(res[i]))
                continue;
            else
                return "ERROR";
        }
        return res;
    }
};

class Solution2
{
public:
    bool intersects(vector<int> v1, vector<int> v2)
    {
        vector<int> inter = {max(v1[0], v2[0]), min(v1[1], v2[1])};
        return inter[0] < inter[1];
    }
    vector<vector<int>> removeInterval(vector<vector<int>> &intervals, vector<int> &toBeRemoved)
    {
        vector<vector<int>> ans;
        for (int i = 0; i < intervals.size(); i++)
        {
            if (intervals[i][0] >= toBeRemoved[0] && intervals[i][1] <= toBeRemoved[1])
                continue;
            else if (intersects(intervals[i], toBeRemoved))
            {
                if (intervals[i][0] < toBeRemoved[0])
                {
                    ans.push_back({intervals[i][0], toBeRemoved[0]});
                }
                else if (intervals[i][1] > toBeRemoved[1])
                {
                    ans.push_back({toBeRemoved[1], intervals[i][1]});
                }
            }
            else
            {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};

class Solution3
{
public:
    int updateddfs(vector<pair<vector<int>,int>> &tree,int i){
        
        for(int j=0;j<tree[i].first.size();j++){
            tree[i].second+=updateddfs(tree,tree[i].first[j]);
        }
        return tree[i].second;
    }
    void count_nodes(vector<pair<vector<int>,int>> tree,int i,int &count){
        if(tree[i].second==0) return ;
        count++;
        for(int j=0;j<tree[i].first.size();j++)
            count_nodes(tree,j,count);
        return;
    }
    int deleteTreeNodes(int nodes, vector<int> &parent, vector<int> &value)
    {
        vector<pair<vector<int>,int>> tree(nodes);
        for(int i=0;i<parent.size();i++){
            if(parent[i]>=0){
                tree[parent[i]].first.push_back(i);
            }
            tree[i].second=value[i];
        }
        
        updateddfs(tree,0);
        int ans=0;
        set<int> invalid;
        if(tree[0].second==0) return 0;
        for(int i=1;i<parents.size();i++){
            if(invalid.count(parent[i]) || tree[i].second==0) invalid.insert(i);
            else ans++;
        }
        return ans;
    }

};
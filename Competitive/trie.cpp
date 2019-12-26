#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int max_child = 26;

struct Trie
{
    vector<Trie *> children;
    bool eo_word;
    Trie()
    {
        eo_word = false;
        children.reserve(26);
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }
};
void insert( Trie *root, const string key)
    {
        struct Trie *itr = root;
        for (int i = 0; i < key.length(); i++)
        {
            if (!itr->children[key[i] - 'a'])
            {
                itr->children[key[i] - 'a'] = new Trie();
                itr = itr->children[key[i] - 'a'];
            }
            itr->eo_word = true;
        }
    }
    bool isLastNode(struct Trie *root)
    {
        bool ans = true;
        for (auto i : root->children)
            ans &= (!i);
        return ans;
    }
    void suggestionsRec(struct Trie *root, string currPrefix, vector<string> &ans)
    {
        if (root->eo_word)
        {
            ans.push_back(currPrefix);
        }
        if (isLastNode(root))
            return;
        for (int i = 0; i < max_child; i++)
        {
            if (root->children[i])
            {
                currPrefix.push_back(97 + i);
                suggestionsRec(root->children[i], currPrefix, ans);
            }
        }
    }
    Trie *suggestions(Trie *root, string q, vector<string> &ans)
    {
        if (root)
            return;
        if (ans.size() > 3)
            return;
        auto itr = root;
        for (int i = 0; i < q.length(); i++)
        {
            int index = q[i] - 'a';
            if (!itr->children[index])
                return itr->children[index];
            itr = itr->children[index];
        }
        bool word = itr->eo_word;
        bool isLast = isLastNode(itr);
        if (word && isLast)
        {
            ans.push_back(q);
            return root;
        }
        if (!isLast)
        {
            string pf = q;
            suggestions(itr, pf,ans);
            return itr;
        }
        return root;
    }
    class Solution
    {
    public:
        vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
        {
            Trie *root = new Trie;
            for (auto i : products)
            {
                insert(root, i);
            }
            vector<vector<string>> res;
            for (int i = 0; i < searchWord.length(); i++)
            {
                vector<string> ans;
                root = suggestions(root, searchWord.substr(0, i + 1), ans);
                res.push_back(ans);
            }
            return res;
        }
};
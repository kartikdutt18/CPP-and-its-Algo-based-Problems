//  https : //leetcode.com/problems/implement-trie-prefix-tree/
#include<iostream>
#include<bits/stdc++.h>
        using namespace std;

struct TrieNode
{
public:
    unordered_map<char, TrieNode *> children;
    bool endOfWord;
    TrieNode(bool endofWord = false) : endOfWord(endofWord){};
};
class Trie
{
    TrieNode *root;

public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        int i = 0;
        TrieNode *itr = root;
        while (i < word.length())
        {
            if (itr->children.count(word[i]))
            {
                itr = itr->children[word[i]];
            }
            else
            {
                TrieNode *temp = new TrieNode();
                itr->children.insert(make_pair(word[i], temp));
                itr = temp;
            }
            i++;
            if (i == word.length())
            {
                itr->endOfWord = true;
            }
        }
        return;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        TrieNode *itr = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!itr->children.count(word[i]))
            {
                return false;
            }
            itr = itr->children[word[i]];
        }
        return itr->endOfWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        TrieNode *itr = root;
        for (int i = 0; i < prefix.length(); i++)
        {
            if (!itr->children.count(prefix[i]))
            {
                return false;
            }
            itr = itr->children[prefix[i]];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
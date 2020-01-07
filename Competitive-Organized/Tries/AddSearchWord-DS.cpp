//https://leetcode.com/problems/add-and-search-word-data-structure-design/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TrieNode
{
public:
    unordered_map<char, TrieNode *> children;
    bool endOfWord;
};
class WordDictionary
{
    TrieNode *root;

public:
    /** Initialize your data structure here. */
    WordDictionary()
    {
        root = new TrieNode();
    }

    /** Adds a word into the data structure. */
    void addWord(string word)
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

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool hasCharacter(string word, TrieNode *itr, int pos)
    {
        if (pos == word.length())
            return itr->endOfWord;
        bool ans = false;
        if (word[pos] == '.')
        {

            for (auto i : itr->children)
            {
                ans = ans || hasCharacter(word, itr->children[i.first], pos + 1);
                if (ans)
                    break;
            }
        }
        else if (!itr->children.count(word[pos]))
            return false;
        else
        {
            ans = ans || hasCharacter(word, itr->children[word[pos]], pos + 1);
        }
        return ans;
    }
    bool search(string word)
    {
        TrieNode *itr = root;
        return hasCharacter(word, itr, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
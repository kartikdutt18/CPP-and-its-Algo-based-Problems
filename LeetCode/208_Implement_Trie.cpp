#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

class TrieNode
{
public:
  unordered_map<char, TrieNode *> children;
};
class Trie
{
  TrieNode *root;
  char endChar;

public:
  /** Initialize your data structure here. */
  Trie()
  {
    root = new TrieNode();
    endChar = '*';
  }

  /** Inserts a word into the trie. */
  void insert(string word)
  {
    TrieNode *temp = root;
    for (char ch : word)
    {
      if (!temp->children.count(ch))
      {
        temp->children.insert({ch, new TrieNode()});
      }
      temp = temp->children[ch];
    }
    temp->children.insert({endChar, NULL});
  }

  /** Returns if the word is in the trie. */
  bool search(string word)
  {
    return startsWith(word + endChar);
  }

  /** Returns if there is any word in the trie that starts with the given prefix. */
  bool startsWith(string prefix)
  {
    TrieNode *temp = root;
    for (char ch : prefix)
    {
      if (!temp->children.count(ch))
      {
        return false;
      }
      temp = temp->children[ch];
    }
    return true;
  }
};

int main()
{
  return 0;
}
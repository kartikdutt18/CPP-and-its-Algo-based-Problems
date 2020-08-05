#include<iostream>
#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

struct TrieNode
{
  int count;
  unordered_map<char, TrieNode *> children;
  TrieNode(int count = 0) : count(count) {}
};

class Trie
{
  TrieNode *root;

public:
  Trie()
  {
    root = new TrieNode('0');
  }

  void insert(string word)
  {
    TrieNode *curNode = root;
    for (char ch : word)
    {
      if (!curNode->children.count(ch))
        curNode->children.insert({ch, new TrieNode()});

      curNode = curNode->children[ch];
      curNode->count += 1;
    }
  }

  void insert(vector<string> &strings)
  {
    for (string word : strings)
    {
      insert(word);
    }
  }

  // In any order.
  void searchUniquePrefix(vector<string> &uniquePrefix, string curString, TrieNode *curNode)
  {
    if (!curNode)
      return;
    if (curNode->count == 1)
    {
      uniquePrefix.push_back(curString);
      return;
    }

    for (pair<char, TrieNode *> pp : curNode->children)
    {
      string newString = curString + pp.first;
      searchUniquePrefix(uniquePrefix, newString, pp.second);
    }
  }
  // In any order.
  void searchUniquePrefix(vector<string> &ans)
  {
    searchUniquePrefix(ans, "", root);
  }

  string shortestUniquePrefix(string word)
  {
    string curString = "";
    TrieNode *curNode = root;
    for (char ch : word)
    {
      if (!curNode->children.count(ch))
        return "";

      curNode = curNode->children[ch];
      curString = curString + ch;
      if (curNode->count == 1)
      {
        return curString;
      }
    }
    return word;
  }
};

vector<string> prefix(vector<string> &A)
{
  Trie trie;
  trie.insert(A);
  vector<string> uniquePrefix;
  // trie.searchUniquePrefix(uniquePrefix);
  for (string word : A)
  {
    string prefix = trie.shortestUniquePrefix(word);
    uniquePrefix.push_back(prefix);
  }
  return uniquePrefix;
}


int main()
{
  ios::sync_with_stdio(false);
  return 0;
}
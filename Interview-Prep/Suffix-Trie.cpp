#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

class TrieNode
{
  public:
  unordered_map<char, TrieNode*> children;
};

// Iterative
class SuffixTrie
{
  TrieNode* root;
  char endChar;

  public:
  SuffixTrie(string str)
  {
    endChar = '*';
    root = new TrieNode();
    this->populateSuffixTrieFrom(str);
  }

  void populateSuffixTrieHelper(string str, TrieNode* node)
  {
    for(char ch : str)
    {
      if (!node->children.count(ch))
      {
        TrieNode* temp = new TrieNode();
        node->children.insert({ch, temp});
      }
      node = node->children[ch];
    }
    node->children.insert({endChar, NULL});
  }
  // O(N**2) / O(N).
  void populateSuffixTrieFrom(string str)
  {
    
    for(int i = 0; i < str.length(); i++)
    {
      TrieNode *temp = root;
      populateSuffixTrieHelper(str.substr(i), temp);
    }
  }

  // O(str.length()) / O(1)
  bool contains(string str)
  {
    TrieNode* temp = root;
    for(char ch : str)
    {
      if (!temp->children.count(ch))
        return false;
      temp = temp->children[ch];
    }
    return temp->children.count(endChar);
  }
};

// Recursive.
class SuffixTrieRecursive
{
public:
  TrieNode *root;
  char endSymbol;

  SuffixTrieRecursive(string str)
  {
    this->root = new TrieNode();
    this->endSymbol = '*';
    this->populateSuffixTrieFrom(str);
  }

  void populateSuffixTrieHelper(TrieNode *node, string str, int i)
  {
    if (i >= str.length())
    {
      node->children.insert({this->endSymbol, NULL});
      return;
    }
    if (!node->children.count(str[i]))
    {
      node->children.insert({str[i], new TrieNode()});
    }
    populateSuffixTrieHelper(node->children[str[i]], str, i + 1);
    return;
  }
  // O(N**2) / O(N**2)
  void populateSuffixTrieFrom(string str)
  {
    for (int i = 0; i < str.length(); i++)
    {
      TrieNode *temp = this->root;
      populateSuffixTrieHelper(temp, str, i);
    }
  }

  bool containsHelper(TrieNode *node, string str, int i)
  {
    if (!node)
      return false;
    if (i >= str.length())
      return node->children.count(this->endSymbol);
    if (!node->children.count(str[i]))
      return false;
    return containsHelper(node->children[str[i]], str, i + 1);
  }
  // O(M) / O(1)
  bool contains(string str)
  {
    TrieNode *temp = this->root;
    return containsHelper(temp, str, 0);
  }
};

int main()
{

return 0;
}
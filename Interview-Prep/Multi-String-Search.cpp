#include <vector>
#include <bits/stdc++.h>
using namespace std;
struct TrieNode
{
  unordered_map<char, TrieNode *> children;
};
class SuffixTrie
{
  TrieNode *root;
  char endSymbol;

public:
  SuffixTrie()
  {
    this->root = new TrieNode();
    this->endSymbol = '*';
  }
  SuffixTrie(string str)
  {
    this->root = new TrieNode();
    this->endSymbol = '*';
    populateTrie(str);
  }
  void populateHelper(TrieNode *node, string str)
  {
    for (char letter : str)
    {
      if (!node->children.count(letter))
      {
        TrieNode *temp = new TrieNode();
        node->children.insert({letter, temp});
      }
      node = node->children[letter];
    }
    node->children.insert({endSymbol, NULL});
  }
  void populateTrie(string str)
  {
    for (int i = 0; i < str.length(); i++)
    {
      TrieNode *temp = root;
      populateHelper(root, str.substr(i));
    }
  }
  bool contains(string str)
  {
    TrieNode *temp = root;
    for (char letter : str)
    {
      if (!temp->children.count(letter))
        return false;
      temp = temp->children[letter];
    }
    return true;
  }
};
vector<bool> multiStringSearch(string bigString, vector<string> smallStrings)
{
  SuffixTrie st(bigString); // O(B**2)
  vector<bool> ans;
  for (string str : smallStrings) // O(N * s)
  {
    ans.push_back(st.contains(str));
  }
  return ans;
}

int main()
{

  return 0;
}
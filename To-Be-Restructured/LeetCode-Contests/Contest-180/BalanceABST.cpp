#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

class TreeNode
{
  public:
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int val):val(val),left(NULL),right(NULL){}
};

// Method 1: 
class Solution {
  public:
  vector<int> tree;
  void Inorder(TreeNode* root)
  {
    if(!root)
      return;
    if(root->left)
      Inorder(root->left);
    tree.push_back(root->val);
    if(root->right)
      Inorder(root->right);
    return;
  }
  TreeNode* BuildTree(int start, int end)
  {
    if (start > end || start<0)
        return NULL;
    int mid = (start+end)/2;
    TreeNode* root=new TreeNode(tree[mid]);
    root->left=BuildTree(start, mid -1);
    root->right=BuildTree(mid+1, end);
    return root;
  }
  TreeNode* balanceBST(TreeNode* root)
  {
    Inorder(root);
    return BuildTree(0, tree.size()-1);
  }
};

int main() {

return 0;
}
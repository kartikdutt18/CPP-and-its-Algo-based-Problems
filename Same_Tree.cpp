
#include<iostream>
#include<bits/stdc++.h>
using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSameTree(TreeNode* p, TreeNode* q){
    if(p==NULL and q==NULL) return true;
    else if(p==NULL or  q==NULL) return false; 
    else{
        if(p->val==q->val){
            return (isSameTree(p->right,q->right)&&isSameTree(p->left,q->left));
        }
        else{
            return false;
        }
    }
}
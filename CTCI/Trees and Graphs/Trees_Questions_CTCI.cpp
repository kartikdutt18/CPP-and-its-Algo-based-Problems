//CTCI
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL) , right(NULL) {}
};

TreeNode* buildTree(int low,int high,vector<int> arr){
    if(low>=high) return NULL;
    int mid=(low+high)/2;
    TreeNode* node=new TreeNode(arr[mid]);
    node->left=buildTree(low,mid-1,arr);
    node->right=buildTree(mid+1,high,arr);
    return node;
}

vector<list<int>> buildLL(TreeNode* root){
    if(!root) return {};
    queue<TreeNode*> q;
    q.push(root);
    vector<list<int>> ans;
    while(!q.empty()){
        list<int> l;
        int len=q.size();
        for(int i=0;i<len;i++){
            auto cur=q.front();
            l.emplace_back(cur->val);
            q.pop();
            if(cur->left) q.emplace(cur->left);
            if(cur->right) q.emplace(cur->right);
        }
        ans.emplace_back(l);
    }
    return ans;
}

int balanced(TreeNode* root){
    if(!root) return 0;
    int left_ht=balanced(root->left);
    if(left_ht==-1) return -1;
    int right_ht = balanced(root->right);
    if(abs(right_ht-left_ht)>1) return -1;
    return max(left_ht,right_ht)+1;
}

bool isBST(TreeNode* root,int minv=INT_MIN,int maxv=INT_MAX){
    if(!root) return true;
    if(root->val<minv || root->val>maxv) return false;
    return isBST(root->left, minv,root->val) && isBST(root->right, root->val, maxv);
}

int GetSuccessor(TreeNode* root,int val){
    if(!root) return -1;
    TreeNode* lga=root; //Least Greater Ancestor == Node at Last Left 
    while(root){
        if(root->val==val) break;
        if(root->val>val){
            lga = root;
            root=root->left;
        }
        else root=root->right;
    }
    if(!root) return -1;
    if(!root->right) return lga->val;
    root=root->right;
    while(root->left){
        root=root->left;
    }
    return root->val;
}
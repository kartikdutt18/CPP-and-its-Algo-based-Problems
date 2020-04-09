//https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x):val(x),right(NULL),left(NULL){}
};
void InOrderTravel(TreeNode* root,vector<pair<TreeNode*,int>> &ans,int dist,TreeNode* target,int &ind){
    if(root==NULL) return;
    
    
    InOrderTravel(root->left,ans,dist+1,target,ind);
    if (root == target)ind = ans.size();
    ans.push_back(pair(root,dist));
    InOrderTravel(root->right, ans, dist + 1,target,ind);
    
    
}
TreeNode* GetParent(TreeNode* root,TreeNode*target){
    if(root==NULL) return NULL;
    if(root->right){
        if(root->right==target){
            return root;
        }
        else{
            GetParent(root->right,target);
        }
    }
    if (root->left)
    {
        if (root->left == target)
        {
            return root;
        }
        else
        {
            GetParent(root->left, target);
        }
    }
return root;}
vector<int> distanceK(TreeNode *root, TreeNode *target, int K)
{   if(root==NULL) return {};
    
    vector<pair<TreeNode*,int>> travel;
    vector<int> ans;
    int target_ind=0;
    int root_ind;
    TreeNode* parent_val=GetParent(root,target);
    InOrderTravel(root, travel, 0, target, target_ind);
    for(int i=0;i<travel.size();i++){
        if(travel[i].first==parent_val) {
            root_ind=i;
            break;
        }
    }
    
    //left sub tree
    int mult1=target_ind<=root_ind?-1:1;
    int mult2 = target_ind > root_ind ? 1 : -1;
    for(int i=0;i<travel.size();i++){
        int dist_from_k;
         if (root_ind >= i) dist_from_k = abs(travel[i].second + mult1 * travel[target_ind].second);
         else   dist_from_k = abs(travel[i].second +mult2*travel[target_ind].second);

        if (dist_from_k == K) ans.push_back(travel[i].first->val);
        }

return ans;}



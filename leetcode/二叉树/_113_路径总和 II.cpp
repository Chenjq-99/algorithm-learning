#include<iostream>
using namespace std;
#include<vector>
#include<stack>
#include<queue>

// https://leetcode.cn/problems/path-sum-ii/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res; 
        vector<int> v;
        dfs(root,targetSum,res,v);
        return res;
    }

    void dfs(TreeNode* root, int targetSum,  vector<vector<int>>& res, vector<int>& v){
        if(root == nullptr) return ;
        v.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr && root->val == targetSum){
            res.push_back(v);
        }
        dfs(root->left,targetSum-root->val,res,v);
        dfs(root->right,targetSum-root->val,res,v);
        v.pop_back();
    }
};
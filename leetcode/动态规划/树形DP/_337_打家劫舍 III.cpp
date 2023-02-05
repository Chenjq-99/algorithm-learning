#include<unordered_map>
using namespace std;

// https://leetcode.cn/problems/house-robber-iii

//  * Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
    unordered_map<TreeNode*, int> f1, f2; //f1Íµ£¬f2²»Íµ
    int dfs(TreeNode* root, int st) {
        if (!root) return 0;
        if (st == 0 && f1[root] != 0) return f1[root];
        if (st == 1 && f2[root] != 0) return f2[root];
        if (st == 0) return f1[root] = root->val + dfs(root->left, 1) + dfs(root->right, 1);
        return f2[root] = max(dfs(root->left, 0), dfs(root->left, 1)) + max(dfs(root->right, 0), dfs(root->right, 1));
    }
public:
    int rob(TreeNode* root) {
        return max(dfs(root, 0), dfs(root, 1));
    }
};
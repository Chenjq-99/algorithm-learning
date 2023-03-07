// https://leetcode.cn/problems/kth-largest-sum-in-a-binary-tree
#include<bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        vector<long long> res;
        q.push(root);
        int levelSize = 1;
        long long sum = 0;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            sum += node->val;
            levelSize--;
            if(node->left != NULL) q.push(node->left);
            if(node->right != NULL) q.push(node->right);
            if(levelSize == 0) {
                res.push_back(sum);
                levelSize = q.size();
                sum = 0;
            }
        }
        sort(res.begin(), res.end(), greater<>());
        if (res.size() < k) return -1;
        return res[k - 1];
    }
};
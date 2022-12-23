#include<vector>
using namespace std;
// https://leetcode.cn/problems/closest-nodes-queries-in-a-binary-search-tree/
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
private:
    vector<int> record;
    void inorder(TreeNode* node) {
        if (node == nullptr) return;
        inorder(node->left);
        record.push_back(node->val);
        inorder(node->right);
    }
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        int n = queries.size();
        vector<vector<int>> ans(n,vector<int>(2)); 
        inorder(root);
        for (int i = 0; i < n; i++) {
            auto minIdx = lower_bound(record.begin(), record.end(), queries[i] + 1);
            ans[i][0] = (minIdx == record.begin()) ? -1 : *(--minIdx);
            auto maxIdx = lower_bound(record.begin(), record.end(), queries[i]);
            ans[i][1] = (maxIdx == record.end()) ? -1 : *maxIdx;
        }
        return ans;
    }
};
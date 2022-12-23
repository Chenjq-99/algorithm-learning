#include<vector>
using namespace std;
// https://leetcode.cn/problems/unique-binary-search-trees-ii/description/
//  Definition for a binary tree node.
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
    vector<TreeNode*> generateTrees(int begin, int end) {
        if(begin > end) return {nullptr};
        vector<TreeNode*> res;
        for(int i = begin; i <= end; i++){
            vector<TreeNode*> leftTrees = generateTrees(begin, i - 1);
            vector<TreeNode*> rightTrees = generateTrees(i + 1, end);
            for(auto leftTree : leftTrees){
                for(auto rightTree : rightTrees){
                    TreeNode* root = new TreeNode(i);
                    root->left = leftTree;
                    root->right = rightTree;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return {};
        return generateTrees(1,n);
    }
};
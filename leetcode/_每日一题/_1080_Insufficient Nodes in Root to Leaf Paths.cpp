#include<functional>
using namespace std;
// https://leetcode.cn/problems/insufficient-nodes-in-root-to-leaf-paths/
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *sufficientSubset(TreeNode *root, int limit)
    {
        function<bool(TreeNode *, int)> dfs = [&](TreeNode *root, int sum)
        {
            if (!root->left && !root->right)
                return sum + root->val >= limit;
            bool l = false, r = false;
            if (root->left)
                l = dfs(root->left, sum + root->val);
            if (root->right)
                r = dfs(root->right, sum + root->val);
            if (!l)
                root->left = nullptr;
            if (!r)
                root->right = nullptr;
            return l || r;
        };
        if (dfs(root, 0))
            return root;
        return nullptr;
    }
};
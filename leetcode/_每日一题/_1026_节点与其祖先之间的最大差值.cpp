// https://leetcode.cn/problems/maximum-difference-between-node-and-ancestor/description/
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
    TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
    int ans = -2e9;
    pair<int, int> dfs(TreeNode* root) {
        if (!root->left && !root->right) return make_pair(root->val, root->val);
        int v = root->val;
        int l_min = v, l_max = v;
        int r_min = v, r_max = v;
        if (root->left) {
            auto p = dfs(root->left);
            l_min = p.first;
            l_max = p.second;
        }
        if (root->right) {
            auto p = dfs(root->right);
            r_min = p.first;
            r_max = p.second;
        }
        ans = max(ans, max({abs(v - l_min), abs(v - l_max), abs(v - r_min), abs(v - r_max)}));
        return make_pair(min({v, l_min, r_min}), max({v, l_max, r_max}));
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
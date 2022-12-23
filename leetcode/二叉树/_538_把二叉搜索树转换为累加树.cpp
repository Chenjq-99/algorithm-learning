#include<iostream>
using namespace std;
#include<vector>
#include<stack>
#include<queue>

// https://leetcode.cn/problems/convert-bst-to-greater-tree/
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
    TreeNode* convertBST(TreeNode* root) {
        dfs(root);
        return root;
    }
private:
    int preSum = 0;
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->right);
        root->val += preSum;
        preSum = root->val;
        dfs(root->left);
    }
};
int main(){
    return 0;
}
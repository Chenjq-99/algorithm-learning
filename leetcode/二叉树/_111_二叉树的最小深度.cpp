#include<iostream>
using namespace std;
#include<vector>
#include<stack>

// https://leetcode.cn/problems/minimum-depth-of-binary-tree/
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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int left = minDepth(root->left);
        int right = minDepth(root->right); 
        if(left == 0 && right== 0) return 1;
        else if(left != 0 && right == 0) return left + 1;
        else if(left == 0 && right != 0) return right + 1;
        else return min(left,right) + 1;       
    }
};

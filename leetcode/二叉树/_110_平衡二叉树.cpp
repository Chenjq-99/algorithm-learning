#include<iostream>
using namespace std;
#include<vector>
#include<stack>

// https://leetcode.cn/problems/balanced-binary-tree/
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
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        int leftDepth = getDepth(root->left);
        int rightDepth = getDepth(root->right);
        if(abs(leftDepth - rightDepth)<= 1) return isBalanced(root->left) && isBalanced(root->right);
        return false;
         
    }
private:
    int getDepth(TreeNode* root){
        if(root == nullptr) return 0;
        return max(getDepth(root->left),getDepth(root->right)) + 1;
    }
};
int main(){
    return 0;
}
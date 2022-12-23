#include<iostream>
using namespace std;
#include<vector>
#include<stack>

// https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty()) return nullptr;
        return traversal(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
private:
    TreeNode* traversal(vector<int>& preorder, int preorderBegin, int preorderEnd, vector<int>& inorder, int inorderBegin, int inorderEnd){

        if(preorderBegin == preorderEnd) return nullptr; // 空

        int rootValue = preorder[preorderBegin];
        TreeNode* root = new TreeNode(rootValue);

        if(preorderEnd - preorderBegin == 1) return root; // 只有一个元素

        int delimiterIndex;
        for(delimiterIndex = inorderBegin; delimiterIndex < inorderEnd; delimiterIndex++){
            if(inorder[delimiterIndex] == rootValue) break;
        }

        // 分割inorder 根据delimiterIndex
        // 左子树
        int leftInorderBegin = inorderBegin;
        int leftInorderEnd = delimiterIndex;
        // 右子树
        int rightInorderBegin = delimiterIndex + 1;
        int rightInorderEnd = inorderEnd;

        // 分割preorder 根据leftInorder 和 rightInorder 的大小;
        // 左子树
        int leftPreorderBegin = preorderBegin + 1;
        int leftPreorderEnd = preorderBegin + 1 + delimiterIndex - inorderBegin;
        // 右子树
        int rightPreorderBegin = preorderBegin + 1 + delimiterIndex - inorderBegin;
        int rightPreorderEnd = preorderEnd;

        root->left = traversal(preorder, leftPreorderBegin, leftPreorderEnd, inorder, leftInorderBegin, leftInorderEnd);
        root->right = traversal(preorder, rightPreorderBegin, rightPreorderEnd, inorder, rightInorderBegin, rightInorderEnd);

        return root;
    }
};
int main(){
    return 0;
}
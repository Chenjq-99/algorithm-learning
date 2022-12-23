#include<iostream>
using namespace std;
#include<vector>
#include<stack>

// https://leetcode.cn/problems/delete-node-in-a-bst/

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;

        TreeNode* node = root;
        while(node){
            if(node->val == key) break;
            else if(node->val > key) node = node->left;
            else node = node->right;
        }
        // node 就是要删除的节点
        if(!node) return root;
        if(node->left && node->right){
            // 要删除的节点度为2

            // 在左子树中找前驱节点
            TreeNode* predecessor = node->left;
            while(predecessor->right){
                predecessor = predecessor->right;
            }
            // predecessor 为前驱节点；
            // 用前驱节点的值覆盖要删除节点的值
            node->val = predecessor->val;
            // 删除前驱节点
            node = predecessor;
        }
        // 删除node node的度为0 或 1
        TreeNode* replacement = node->left != nullptr ? node->left : node->right;
        // 要删除的节点是根节点
        if(node == root) return replacement;
        // 找到要删除节点的父节点
        TreeNode* parent = root;
        while(1){
            if(parent->left == node || parent->right == node) break;
            else if(parent->val >= node->val) parent = parent->left;
            else parent = parent->right;
        }
        // parent是node的父节点
        if(parent->left == node) parent->left = replacement;
        else parent->right = replacement;
        return root;
    }

};
int main(){
    return 0;
}
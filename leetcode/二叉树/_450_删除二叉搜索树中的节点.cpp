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
        // node ����Ҫɾ���Ľڵ�
        if(!node) return root;
        if(node->left && node->right){
            // Ҫɾ���Ľڵ��Ϊ2

            // ������������ǰ���ڵ�
            TreeNode* predecessor = node->left;
            while(predecessor->right){
                predecessor = predecessor->right;
            }
            // predecessor Ϊǰ���ڵ㣻
            // ��ǰ���ڵ��ֵ����Ҫɾ���ڵ��ֵ
            node->val = predecessor->val;
            // ɾ��ǰ���ڵ�
            node = predecessor;
        }
        // ɾ��node node�Ķ�Ϊ0 �� 1
        TreeNode* replacement = node->left != nullptr ? node->left : node->right;
        // Ҫɾ���Ľڵ��Ǹ��ڵ�
        if(node == root) return replacement;
        // �ҵ�Ҫɾ���ڵ�ĸ��ڵ�
        TreeNode* parent = root;
        while(1){
            if(parent->left == node || parent->right == node) break;
            else if(parent->val >= node->val) parent = parent->left;
            else parent = parent->right;
        }
        // parent��node�ĸ��ڵ�
        if(parent->left == node) parent->left = replacement;
        else parent->right = replacement;
        return root;
    }

};
int main(){
    return 0;
}
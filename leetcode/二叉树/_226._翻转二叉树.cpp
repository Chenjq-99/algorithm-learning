#include<iostream>
using namespace std;
#include<queue>

/**
 * https://leetcode-cn.com/problems/invert-binary-tree/
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
// public:
//     TreeNode* invertTree(TreeNode* root) {
//         if(root == NULL){return root;}

//         TreeNode* temp = root->left;
//         root->left = root->right;
//         root->right = temp;

//         invertTree(root->left);
//         invertTree(root->right);

//         return root;
//     }
// public:
//     TreeNode* invertTree(TreeNode* root) {
//         if(root == NULL){return root;}

//         invertTree(root->left);
//         invertTree(root->right);

//         TreeNode* temp = root->left;
//         root->left = root->right;
//         root->right = temp;
        
//         return root;
//     }
// public:
//     TreeNode* invertTree(TreeNode* root) {
//         if(root == NULL){return root;}

//         invertTree(root->left);
        

//         TreeNode* temp = root->left;
//         root->left = root->right;
//         root->right = temp;

//         invertTree(root->left);
        
//         return root;
//     }

public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL){return root;}

        queue<TreeNode*> queue;
        queue.push(root);

        while (!queue.empty())
        {
            TreeNode* node = queue.front();
            queue.pop();

            TreeNode* temp = node->left;
            node->left = node->right;
            node->right = temp;

            if(node->left != NULL)
            {
                queue.push(node->left);
            }

            if(node->right != NULL)
            {
                queue.push(node->right);
            }
        }
        
        return root;
    }
};










int main(){
    return 0;
}
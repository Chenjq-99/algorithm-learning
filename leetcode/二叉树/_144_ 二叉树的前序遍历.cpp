#include<iostream>
using namespace std;
#include<vector>
#include<stack>

/**
 * https://leetcode-cn.com/problems/binary-tree-preorder-traversal/
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
public:
    vector<int> preorderTraversal(TreeNode* root) {

        #if 0
        // µÝ¹é
        vector<int> v;
        if(root == NULL){return v;}

        v.push_back(root->val);

        vector<int> v2 = preorderTraversal(root->left);

        v.insert(v.end(), v2.begin(),v2.end());

        vector<int> v3 = preorderTraversal(root->right);

        v.insert(v.end(), v3.begin(),v3.end());

        return v;
        #endif

        //µü´ú
        vector<int> vector;
        stack<TreeNode*> stack;

        if(root == NULL){return vector;}

        stack.push(root);

        TreeNode* node = NULL;

        while(!stack.empty())
        {
            node = stack.top();
            stack.pop();

            vector.push_back(node->val);

            if(node->right != NULL)
            {
                stack.push(node->right);
            }
            
            if(node->left != NULL)
            {
                stack.push(node->left);
            }

        }

        return vector;
    }
};

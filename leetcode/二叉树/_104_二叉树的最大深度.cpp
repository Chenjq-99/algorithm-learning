#include<iostream>
using namespace std;
#include<queue>

/**
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
};
 


class Solution {
public:
    int maxDepth(TreeNode* root) {

        
        if(root == NULL){return 0;}

        // µü´ú

        // int height = 0;

        // int levelSize = 1;

        // queue<TreeNode*> queue;

        // queue.push(root);

        // while(!queue.empty())
        // {
        //     TreeNode* node = queue.front();
        //     queue.pop();

        //     levelSize--;

        //     if(node->left != NULL)
        //     {
        //         queue.push(node->left);
        //     }

        //     if(node->right != NULL)
        //     {
        //         queue.push(node->right);
        //     }

        //     if(levelSize == 0)
        //     {
        //         height++;
        //         levelSize = queue.size();
        //     }
        // }

        // return height;

        // µÝ¹é
        return 1+max(maxDepth(root->left),maxDepth(root->right));

    }
};
int main(){
    return 0;
}
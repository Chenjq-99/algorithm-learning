#include<iostream>
using namespace std;
#include<vector>
#include<queue>

/**
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
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
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> Vector;
        vector<int> vector;
        queue<TreeNode*> queue;

        int levelSize = 1;

        if(root == NULL){return Vector;}

        queue.push(root);

        while(!queue.empty())
        {
            TreeNode * node = queue.front();
            queue.pop();

            vector.push_back(node->val);

            levelSize--;

            if(node->left != NULL)
            {
                queue.push(node->left);
            }

            if(node->right != NULL)
            {
                queue.push(node->right);
            }

            if(levelSize == 0)
            {
                Vector.push_back(vector);
                vector.clear();
                levelSize = queue.size();
            }
        }

        return Vector;       

    }
};
/*
*NOTE:
*这道题本质上时层序遍历+判断本层是否遍历结束
*定义int levelSize = 1; 表示本层剩余没遍历的节点数
*每次从队列里出队一个节点，levelSize应减一
*当leveSize == 0时，表示本层遍历完毕
*levelSize更新为下一层的节点数量，即队列的大小
*/ 

int main(){
    return 0;
}
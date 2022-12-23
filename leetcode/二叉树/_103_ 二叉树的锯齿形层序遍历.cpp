#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<algorithm>

/**
 * https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> Vector;

        if(root == NULL){return Vector;}

        vector<int> vector;

        queue<TreeNode*> queue;

        queue.push(root);

        int levelSize = 1;

        bool flag = true;

        while(!queue.empty())
        {
            TreeNode* node = queue.front();
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
                if(!flag)
                {
                    reverse(vector.begin(),vector.end());
                }

                Vector.push_back(vector);

                vector.clear();

                flag = !flag;

                levelSize = queue.size();
            }
        }

        return Vector;

    }
};

int main(){
    return 0;
}
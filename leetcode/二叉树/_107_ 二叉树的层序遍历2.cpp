#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
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
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
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
        reverse(Vector.begin(),Vector.end());
        return Vector;   
    }
};

int main(){
    return 0;
}
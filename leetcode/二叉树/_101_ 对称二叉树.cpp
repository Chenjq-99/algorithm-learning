#include<iostream>
using namespace std;
#include<vector>
#include<stack>
#include<queue>

// https://leetcode.cn/problems/symmetric-tree/submissions/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// µü´ú
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        
        queue<TreeNode*> que;
        que.push(root->left);
        que.push(root->right);

        while(!que.empty()){
            TreeNode* left_node = que.front();
            que.pop();
            TreeNode* right_node = que.front();
            que.pop();
            if(!left_node && !right_node) continue;
            if(!left_node || !right_node || left_node->val != right_node->val) return false;

            que.push(left_node->left);
            que.push(right_node->right);
            que.push (left_node->right);
            que.push(right_node->left);            
        }
        return true;
    }
};
// µÝ¹é
class Solution {
public:
    bool compare(TreeNode* left, TreeNode* right) {
        if (left == NULL && right != NULL) return false;
        else if (left != NULL && right == NULL) return false;
        else if (left == NULL && right == NULL) return true;
        else if (left->val != right->val) return false;
        else return compare(left->left, right->right) && compare(left->right, right->left);

    }
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return compare(root->left, root->right);
    }
};
int main(){
    return 0;
}
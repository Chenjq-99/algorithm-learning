#include<iostream>
using namespace std;
#include<vector>
#include<stack>
#include<queue>

// https://leetcode.cn/problems/subtree-of-another-tree/

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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot) return true;
        if(!root || !subRoot) return false;       
        return isSameTree(root,subRoot) || isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);     
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;

        queue<TreeNode*> queue;
        queue.push(p);
        queue.push(q);
        TreeNode* left = p;
        TreeNode* right = q;
        while(!queue.empty()){
            left = queue.front();
            queue.pop();
            right = queue.front();
            queue.pop();

            if(!left && !right) continue;
            if(!left || !right || (left->val != right->val)) return false;
            queue.push(left->left);
            queue.push(right->left);
            queue.push(left->right);
            queue.push(right->right);
        }
        return true;
    }
};
int main(){
    return 0;
}
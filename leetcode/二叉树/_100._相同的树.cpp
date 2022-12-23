/*
 * @Description: 
 * @Author: chenjq
 * @Date: 2022-09-08 10:26:01
 * @LastEditTime: 2022-09-08 10:31:06
 * @LastEditors: chenjq
 */
#include<iostream>
using namespace std;
#include<vector>
#include<stack>
#include<queue>

// https://leetcode.cn/problems/same-tree/submissions/
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
// µÝ¹é
class Solution {
public:
    bool compare(TreeNode* left, TreeNode* right) {
        if (left == NULL && right != NULL) return false;
        else if (left != NULL && right == NULL) return false;
        else if (left == NULL && right == NULL) return true;
        else if (left->val != right->val) return false;
        else return compare(left->left, right->left) && compare(left->right, right->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return compare(p,q);
    }
};
int main(){
    return 0;
}
/*
 * @Description: 
 * @Author: chenjq
 * @Date: 2022-09-10 10:37:36
 * @LastEditTime: 2022-09-10 10:41:01
 * @LastEditors: chenjq
 */
#include<iostream>
using namespace std;
#include<vector>
#include<stack>

// https://leetcode.cn/problems/range-sum-of-bst/
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
    int rangeSumBST(TreeNode* root, int low, int high) {
        // µü´ú
        // if(root->left == nullptr && root->right == nullptr) return root->val;
        // stack<TreeNode*> s;
        // TreeNode* node = root;
        // int res = 0;
        // bool flag = false;
        // while(node != nullptr || !s.empty()){
        //     while(node != nullptr){
        //         s.push(node);
        //         node = node->left;
        //     }
        //     node = s.top();
        //     s.pop();
        //     if(flag){
        //         res += node->val;
        //     }
        //     if(node->val == low){
        //         res += node->val;
        //         flag = true;
        //     }
        //     if(node->val == high){
        //         break;
        //     }
        //     node = node->right;
        // }
        // return res;
        // µÝ¹é
        if(!root) return 0;
        if(root->val < low) return rangeSumBST(root->right,low,high);
        else if(root->val > high) return rangeSumBST(root->left,low,high);
        else return rangeSumBST(root->left,low,high) + rangeSumBST(root->right,root->val,high) + root->val;
    }
};
int main(){
    return 0;
}
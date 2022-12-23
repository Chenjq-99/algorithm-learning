#include<iostream>
using namespace std;
#include<vector>
#include<stack>

// https://leetcode.cn/problems/validate-binary-search-tree/
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
    bool isValidBST(TreeNode* root) {
        if(!root || (root->left == nullptr && root->right == nullptr)) return true;
        bool flag = true;
        TreeNode* node = root;
        if(root->left){
            // �ҵ�����������ֵ
            node = root->left;
            while(node->right){
                node = node->right;
            }
            flag  = (node->val < root->val);
        }
        if(root->right && flag){
            // �ҵ���������С��ֵ
            node = root->right;
            while(node->left){
                node = node->left;
            }
            flag  = (node->val > root->val);
        }
        return flag && isValidBST(root->left) && isValidBST(root->right);
    }
};
int main(){
    return 0;
}
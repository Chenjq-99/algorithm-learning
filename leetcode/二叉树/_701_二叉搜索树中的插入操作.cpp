#include<iostream>
using namespace std;
#include<vector>
#include<stack>

// https://leetcode.cn/problems/insert-into-a-binary-search-tree/
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            // 在根节点插入
            root = new TreeNode(val);
        }else{
            // 不在根节点插入
            // 找到要插入节点的父节点
            TreeNode* parent = root;
            TreeNode* node = root;
            int cmp = 0;
            while(node){
                cmp = node->val > val ? 1 : -1;
                parent = node;
                if(cmp > 0) node = node->left;
                else node = node->right;
            }
            // parent就是要插入节点的父节点
            // 判断插入到哪边
            if(cmp > 0) parent->left = new TreeNode(val);
            else parent->right = new TreeNode(val);
        }
        return root;
    }

};

int main(){
    return 0;
}
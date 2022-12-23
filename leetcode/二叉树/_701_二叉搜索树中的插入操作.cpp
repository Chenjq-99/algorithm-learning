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
            // �ڸ��ڵ����
            root = new TreeNode(val);
        }else{
            // ���ڸ��ڵ����
            // �ҵ�Ҫ����ڵ�ĸ��ڵ�
            TreeNode* parent = root;
            TreeNode* node = root;
            int cmp = 0;
            while(node){
                cmp = node->val > val ? 1 : -1;
                parent = node;
                if(cmp > 0) node = node->left;
                else node = node->right;
            }
            // parent����Ҫ����ڵ�ĸ��ڵ�
            // �жϲ��뵽�ı�
            if(cmp > 0) parent->left = new TreeNode(val);
            else parent->right = new TreeNode(val);
        }
        return root;
    }

};

int main(){
    return 0;
}
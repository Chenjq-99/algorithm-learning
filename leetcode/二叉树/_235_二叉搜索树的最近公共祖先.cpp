#include<iostream>
using namespace std;
#include<vector>
#include<stack>

// https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // µü´ú
        // while(root){
        //     if(root->val > p->val && root->val > q->val) root = root->left;
        //     else if(root->val < p->val && root->val < q->val) root = root->right;
        //     else return root;
        // }
        // return root;
        // µÝ¹é
        if(root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left,p,q);
        else if(root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right,p,q);
        return root;
        
    }

    
};
int main(){
    return 0;
}
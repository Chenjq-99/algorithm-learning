#include<iostream>
using namespace std;
#include<vector>
#include<stack>

// https://leetcode.cn/problems/zhong-jian-er-cha-shu-lcof/
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        if(preorder.empty() && inorder.empty()) return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);

        vector<int> newPreorder1;
        vector<int> newInorder1;

        vector<int> newPreorder2;
        vector<int> newInorder2;

        int record = 0;

        for(int i = 0; i < inorder.size(); i++){
            if(inorder[i] == root->val){
                record = i;
                break;
            }
            newPreorder1.push_back(preorder[i+1]);
            newInorder1.push_back(inorder[i]);
        }
        
        for(int i = record; i < inorder.size()-1; i++){
            newPreorder2.push_back(preorder[i+1]);
            newInorder2.push_back(inorder[i+1]);
        }
        
        root->left = buildTree(newPreorder1,newInorder1);
        root->right = buildTree(newPreorder2,newInorder2);

        return root;

    }     
};
int main(){
    return 0;
}
#include<iostream>
using namespace std;
#include<vector>
#include<stack>

// https://leetcode.cn/problems/kth-smallest-element-in-a-bst/
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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> res;
        traversal(root,res,k);
        return res[k-1];
    }
private:
    void traversal(TreeNode* root,vector<int>& res, int k){
        if(!root) return;
        traversal(root->left,res,k);
        if(res.size() < k) res.push_back(root->val);
        traversal(root->right,res,k);
    }
};

int main(){
    return 0;
}
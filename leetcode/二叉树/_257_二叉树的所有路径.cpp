#include<iostream>
using namespace std;
#include<vector>
#include<stack>
#include<queue>

// https://leetcode.cn/problems/binary-tree-paths/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
private:
    vector<int> v;
    vector<string> res;
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root);
        return res;
    }
private:
    void dfs(TreeNode* root){
        if(root == nullptr) return;
        v.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr){
            string str = "";
            for(int i = 0; i < v.size(); i++){
                str += to_string(v[i]);
                if(i != v.size()-1) str += "->";
            }
            res.push_back(str);
        }
        dfs(root->left);
        dfs(root->right);
        v.pop_back();
    }
};
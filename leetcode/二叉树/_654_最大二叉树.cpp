#include<iostream>
using namespace std;
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
// https://leetcode.cn/problems/maximum-binary-tree/
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.empty()) return nullptr;
        auto rootYIterator = max_element(nums.begin(),nums.end());
        TreeNode* root = new TreeNode(*rootYIterator);
        vector<int> leftNums(nums.begin(),rootYIterator);
        vector<int> rightNums(rootYIterator+1,nums.end());
        root->left  = constructMaximumBinaryTree(leftNums);
        root->right = constructMaximumBinaryTree(rightNums);
        return root;
    }
};
int main(){
    return 0;
}
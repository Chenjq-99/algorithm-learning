#include<iostream>
using namespace std;
#include<vector>
#include<stack>
#include<queue>

// https://leetcode.cn/problems/maximum-width-of-binary-tree/

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
    int widthOfBinaryTree(TreeNode* root) {

        if(!root) return 0;
        queue<pair<TreeNode*,unsigned long long>> queue;
        queue.push(make_pair(root,1));
        TreeNode* node = nullptr;
        unsigned long long num = 1;
        int levelSize = 1;
        unsigned long long width = 1;
        while(!queue.empty()){
            node = queue.front().first;
            num = queue.front().second;
            queue.pop();
            levelSize--;
            if(node->left) queue.push(make_pair(node->left,2*num-1));
            if(node->right) queue.push(make_pair(node->right,2*num));
            if(levelSize == 0){
                levelSize = queue.size();
                if(!queue.empty()) width = max(width,(queue.back().second-queue.front().second+1));
            }   
        }
        return width;
    }
};

int main(){
    return 0;
}
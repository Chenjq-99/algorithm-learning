#include<iostream>
using namespace std;
#include<vector>
#include<stack>
#include<queue>

// https://leetcode.cn/problems/find-bottom-left-tree-value/submissions/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// µü´ú
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int levelSize = 1;
        int res = root->val;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            levelSize--;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            if(levelSize == 0 ){
                levelSize = q.size();
                if(!q.empty()) res = q.front()->val;
            }
        }
        return res;
    }
};
// µÝ¹é
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {

        if(!root->left && !root->right) return root->val;
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        if(leftHeight >= rightHeight) return findBottomLeftValue(root->left);
        else return findBottomLeftValue(root->right);
    }
private: 
    int getHeight(TreeNode* root){
        if(!root) return 0;
        return max(getHeight(root->left),getHeight(root->right)) + 1;
    }
};
int main(){
    return 0;
}
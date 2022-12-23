#include<iostream>
using namespace std;
#include<vector>
#include<stack>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

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
    vector<int> postorderTraversal(TreeNode* root) {
        
        if(!root) return{};

        vector<int> res;

        #if 0
        vector<int> v1 = postorderTraversal(root->left);

        vector<int> v2 = postorderTraversal(root->right);

        res.insert(res.end(),v1.begin(),v1.end());
        res.insert(res.end(),v2.begin(),v2.end());
        res.push_back(root->val);

        return res;
        #endif

        // µü´ú¸öÈËÐ´
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(root);
        TreeNode* node = root;
        while(!s1.empty()){
            node = s1.top();
            s1.pop();
            s2.push(node);
            if(node->left) s1.push(node->left);
            if(node->right) s1.push(node->right);
        }
        while(!s2.empty()){
            res.push_back(s2.top()->val);
            s2.pop();
        }
        return res;

    }
};

int main(){
    return 0;
}
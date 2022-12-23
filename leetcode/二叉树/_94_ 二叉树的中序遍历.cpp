#include<iostream>
using namespace std;
#include<vector>
#include<stack>


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
    vector<int> inorderTraversal(TreeNode* root) {
        
        #if 0

        // 递归
        vector<int> res;
        
        if(!root){return res;}

        vector<int> v1 = inorderTraversal(root->left);

        vector<int> v2 = inorderTraversal(root->right);

        res.insert(res.end(),v1.begin(),v1.end());
        res.push_back(root->val);
        res.insert(res.end(),v2.begin(),v2.end());

        return res;

        #endif

        // 迭代法
        if(root == nullptr) return{};
        stack<TreeNode*> stack;
        vector<int> res;
        TreeNode* node = root;
        
        while(node != nullptr || !stack.empty()){
            while(node != nullptr){
                stack.push(node);
                node = node->left;
            }

            node = stack.top();
            stack.pop();

            res.push_back(node->val);
            node = node->right;
        }
        #if 0
        // 节点染色法
        if(root == nullptr) return {};

        int white = 0;
        int gray = 1;
        TreeNode* node = root;

        stack<pair<TreeNode*,int>> stack;
        vector<int> res;

        stack.push(make_pair(root,white));

        while(!stack.empty()){
            node = stack.top().first;
            int color = stack.top().second;

            if(color == white){
                stack.push(make_pair(node->right,white));
                stack.push(make_pair(node,gray));
                stack.push(make_pair(node->left,white));
            }else{
                res.push_back(node->val);
            }
        }

        return res; 
    #endif

        
    }
};

int main(){
    return 0;
}
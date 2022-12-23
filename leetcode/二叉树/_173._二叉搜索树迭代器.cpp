#include<iostream>
using namespace std;
#include<vector>
#include<stack>
#include<queue>

// https://leetcode.cn/problems/binary-search-tree-iterator/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        traversal(root,queue);
    }
    
    int next() {
        int res = queue.front()->val;
        queue.pop();
        return res;
    }
    
    bool hasNext() {
        return !(queue.empty());
    }
private:
    ::queue<TreeNode*> queue;

    void traversal(TreeNode* root, ::queue<TreeNode*>& queue){
        if(!root) return;
        traversal(root->left,queue);
        queue.push(root);
        traversal(root->right,queue);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
int main(){
    return 0;
}
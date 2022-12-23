#include<iostream>
using namespace std;
#include<vector>
#include<stack>

// https://leetcode.cn/problems/minimum-absolute-difference-in-bst/
// 与 783.二叉搜索树节点最小距离相同 https://leetcode.cn/problems/minimum-distance-between-bst-nodes/
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
    int getMinimumDifference(TreeNode* root) {
        
        stack<TreeNode*> s;
        TreeNode* node = root;
        int pre = -INT_MAX;
        long min = INT_MAX;
        while(node != nullptr || !s.empty()){
            while(node != nullptr){
                s.push(node);
                node = node->left;
            }           
            node = s.top();
            s.pop();
            int cur = node->val;
            min = min > ((long)cur- (long)pre) ? ((long)cur - (long)pre) : min;
            node = node->right;
            pre = cur;
        }

        return min;
    }
};
int main(){
    return 0;
}
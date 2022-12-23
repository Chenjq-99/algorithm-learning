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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return nullptr;
        return sortedArrayToBST(nums, 0, nums.size());
    }
private:
    TreeNode* sortedArrayToBST(vector<int>& nums, int begin, int end) {
            if(end == begin) return nullptr;
            if(end - begin == 1) return new TreeNode(nums[begin]);
            TreeNode* root = new TreeNode(nums[(begin + end-1)/2]);
            root->left = sortedArrayToBST(nums,begin,(begin + end-1)/2);
            root->right = sortedArrayToBST(nums,(begin + end-1)/2+1, end);
            return root;            
        }
};
int main(){
    return 0;
}
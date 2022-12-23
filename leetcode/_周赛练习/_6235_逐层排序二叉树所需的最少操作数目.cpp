#include<unordered_map>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
// https://leetcode.cn/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/description/
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

    int getMinSwaps(vector<int> &nums)
    {
        unordered_map<int, int> mp;    
        vector<int> sortedNums(nums);
        sort(sortedNums.begin(), sortedNums.end());
        for (int i = 0; i < sortedNums.size(); i++) mp[sortedNums[i]] = i ;//记录下标索引
    
        int cnt = 0;
        for (int i = 0; i < nums.size();i++)
        {
            while(nums[i] != sortedNums[i]) {
                swap(nums[i], nums[mp[nums[i]]]); //交换到nums[i]这个值应该在的位置
                cnt++;
            }
        }
        return cnt;
    }
    // 置换环
    int getMinSwaps2(vector<int>& nums) {

        int n = nums.size();
        vector<int> sortedNums(nums);
        sort(sortedNums.begin(), sortedNums.end());
        unordered_map<int,int> mp;
        for (int i = 0; i < n; i++) {
            mp[sortedNums[i]] = i;
        }
        int cnt = 0;
        vector<bool> st(n, false);
        for (int i = 0; i < n; i++) {
            if(st[i]) continue;
            int j = i;
            while(!st[j]) {
                st[j] = true;
                j = mp[nums[j]];
            }
            cnt++;
        }
        return n - cnt;
    }

    int minimumOperations(TreeNode* root) {
        int res = 0;
        queue<TreeNode*> q;
        int levelSize = 1;
        q.push(root);
        vector<int> level;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            level.push_back(node->val);
            levelSize--;
            if(node->left != nullptr) q.push(node->left);
            if(node->right != nullptr) q.push(node->right);
            if(levelSize == 0){
                res += getMinSwaps(level);
                levelSize = q.size();
                level.clear();
            }
        }
        return res;
    }
};

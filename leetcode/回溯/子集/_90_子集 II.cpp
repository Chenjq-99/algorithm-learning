#include<vector>
#include<algorithm>
using namespace std;

// https://leetcode.cn/problems/subsets-ii/
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIdx, int size, vector<bool>& used) {
        if(path.size() == size){
            result.push_back(path);
            return;
        }
        for(int i = startIdx; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
            if(used[i] == false){
                used[i] = true;
                path.push_back(nums[i]);
                backtracking(nums, i + 1, size, used);
                path.pop_back();
                used[i] = false;
            }
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int size = 0; size <= n; size++){
            vector<bool> used(n,false);
            backtracking(nums, 0, size, used);
        }
        return result;
    }
};
#include<vector>
using namespace std;

// https://leetcode.cn/problems/combination-sum/
class Solution {
public:
    vector<vector<int>> result;
    vector<int> record;
    void backtracking(int begin, int preSum, int target, vector<int>& candidates){
        if(preSum > target) return;
        if(preSum == target){
            result.push_back(record);
            return;
        }
        for(int i = begin; i < candidates.size(); i++){
            record.push_back(candidates[i]);
            backtracking(i, preSum + candidates[i], target, candidates);
            record.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(0,0,target,candidates);
        return result;
    }
};
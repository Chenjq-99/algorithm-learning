#include<vector>
#include<algorithm>
using namespace std;

// https://leetcode.cn/problems/combination-sum-ii/
class Solution {
public:
    vector<vector<int>> result;
    vector<int> record;
    void backtracking(int begin, int preSum, int target, vector<int>& candidates, vector<bool>& used){
        if(preSum > target) return;
        if(preSum == target){
            result.push_back(record);
            return;
        }
        for(int i = begin; i < candidates.size(); i++){
            if(i > 0 && candidates[i] == candidates[i-1] && !used[i - 1]) continue;
            record.push_back(candidates[i]);
            used[i] = true;
            backtracking(i+1, preSum + candidates[i], target, candidates, used);
            record.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(),false);
        sort(candidates.begin(),candidates.end());
        backtracking(0, 0, target, candidates, used);
        return result;
    }
};
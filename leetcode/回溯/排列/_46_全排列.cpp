#include<vector>
#include<unordered_map>
using namespace std;

// https://leetcode.cn/problems/permutations/description/
class Solution {
private:
    vector<vector<int>> result;
    vector<int> v;
    void backtracking(vector<int>& nums, unordered_map<int,int>& visited){
        int n = nums.size();
        if(v.size() == n){
            result.push_back(v);
            return;
        }
        for(int i = 0; i < n; i++){
            if(!visited[nums[i]]){
                visited[nums[i]] = 1;
                v.push_back(nums[i]);
                backtracking(nums, visited);
                v.pop_back();
                visited[nums[i]] = 0;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_map<int,int> visited;
        backtracking(nums, visited);
        return result;
    }
};
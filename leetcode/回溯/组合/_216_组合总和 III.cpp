#include <vector>
#include <algorithm>
using namespace std;

// https://leetcode.cn/problems/combination-sum-iii/
class Solution
{
public:
    vector<vector<int>> result;
    vector<int> record;
    void backtracking(int begin, int k, int preSum, int targetSum)
    {
        if (record.size() == k)
        {
            if (preSum == targetSum)
                result.push_back(record);
            return;
        }
        for (int i = begin; i <= 9 - (k - record.size()) + 1; i++)
        {
            if (preSum + i > targetSum)
                break;
            record.push_back(i);
            backtracking(i + 1, k, preSum + i, targetSum);
            record.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        backtracking(1, k, 0, n);
        return result;
    }
};
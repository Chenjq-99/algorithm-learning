#include<queue>
#include<vector>
using namespace std;
// https://leetcode.cn/problems/maximal-score-after-applying-k-operations/
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int, vector<int>> heap;
        for (int i = 0; i < nums.size(); i++) heap.push(nums[i]);
        long long res = 0;
        while (k--) {
            res += heap.top();
            heap.push((heap.top() + 2) / 3);
            heap.pop();
        }
        return res;
    }
};
#include<vector>
#include<algorithm>
using namespace std;
// https://leetcode.cn/problems/minimum-limit-of-balls-in-a-bag/
class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        sort(nums.begin(), nums.end());
        int l = 1, r = nums.back();
        while (l < r) {
            int mid = l + r >> 1;
            int opts = 0;
            auto it = upper_bound(nums.begin(), nums.end(), mid);
            while (it != nums.end()) {
                opts += (*it - 1) / mid;
                it++;
            }
            if (opts <= maxOperations) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};
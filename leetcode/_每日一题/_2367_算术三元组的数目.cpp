// https://leetcode.cn/problems/number-of-arithmetic-triplets/
#include<vector>
#include<functional>
using namespace std;
class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        function<int(int, int, int)> check = [&](int l, int r, int x) {
            while (l < r) {
                int mid = l + r >> 1;
                if (nums[mid] >= x) r = mid;
                else l = mid + 1;
            }
            return nums[l] == x ? l : -1;
        };
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n -  2; i++) {
            int t1 = check(i + 1, n - 2, nums[i] + diff);
            if (t1 != -1) {
                int t2 = check(t1 + 1, n - 1, nums[i] + diff * 2);
                if (t2 != -1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
#include<vector>
#include<algorithm>
using namespace std;
// https://leetcode.cn/problems/number-of-subarrays-with-gcd-equal-to-k/
class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        for(int i = 0; i < n; i++) {
            int x = nums[i];
            if(x % k != 0) continue;
            for(int j = i; j < n; j++) {
                x = __gcd(x,nums[j]);
                if(x == k) res++;
                if(x < k) break;
            }
        }
        return res;
    }
};
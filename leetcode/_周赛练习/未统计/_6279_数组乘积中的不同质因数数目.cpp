#include<vector>
#include<unordered_set>
using namespace std;
// https://leetcode.cn/problems/distinct-prime-factors-of-product-of-array/
class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> hash;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            for (int i = 2; i <= x / i; i++) {
                if (x % i == 0) hash.insert(i);
                while (x % i == 0) x /= i;
            }
            if (x > 1) hash.insert(x);
        }
        return hash.size();
    }
};
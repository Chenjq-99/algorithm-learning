#include<vector>
#include<algorithm>
#include<map>
using namespace std;

// https://leetcode.cn/problems/number-of-unequal-triplets-in-array/
class Solution {
public:
    // ����ö�� O(n^3)
    int unequalTriplets(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (nums[i] == nums[j] || nums[i] == nums[k] || nums[j] == nums[k]) continue;
                    res++;
                }
            }
        }
        return res;
    }
    // ������ͬ => d�����ִ�Сû��Ҫ�� => ���� O(nlogn)
    int unequalTriplets(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        int begin = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] != nums[i+1]) { // ÿ����ȶε����һλ
                res += begin * (i - begin + 1) * (n - 1 - i);
                begin = i + 1;
            }
        }
        return res;
    }
    // ��map��¼nums������������ֵĴ��� O(n)
    int unequalTriplets(vector<int>& nums) {
        int l = 0, r = nums.size();
        int res = 0;
        map<int,int> mp;
        for (auto& num : nums) {
            mp[num]++;
        }
        for (auto& pair : mp) {
            int cnt = pair.second;
            r -= cnt;
            res += l * cnt * r;
            l += cnt;
        }
        return res;
    }
};
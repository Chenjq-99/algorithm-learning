#include<unordered_map>
#include<vector>
using namespace std;
// https://leetcode.cn/problems/two-out-of-three/
class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_map<int, int> mp;
        for (auto& i : nums1) {
            mp[i] = 1;
        }
        for (auto& i : nums2) {
            mp[i] |= 2;
        }
        for (auto& i : nums3) {
            mp[i] |= 4;
        }
        vector<int> res;
        for (auto& [k, v] : mp) {
            int cnt = 0;
            for (; v; v -= v & (-v)) cnt++;
            if (cnt >= 2) {
                res.push_back(k);
            }
        }
        return res;
    }
};


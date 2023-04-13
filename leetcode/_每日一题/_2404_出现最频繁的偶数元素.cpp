// https://leetcode.cn/problems/most-frequent-even-element/
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int, int> hash;
        for (auto& x : nums) 
            if (!(x & 1))
                hash[x]++;
        int ans = -1, max_fre = 0;
        for (auto& t : hash) {
            if (t.second > max_fre) {
                max_fre = t.second;
                ans = t.first;
            }
        }
        return ans;
    }
};
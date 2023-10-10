#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto& x : nums) {
        	mp[x]++;
        }
        int ans = 0;
        for (auto& [k, v] : mp) {
        	if (v == 1) return -1;
        	else {
        		ans += (v / 3) + (v % 3 != 0);
        	}
        }
        return ans;
    }
};
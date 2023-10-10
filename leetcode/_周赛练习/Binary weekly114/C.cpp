#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int n = nums.size();
        int minv = nums[0];
        for (int i = 1; i < n; i++) minv &= nums[i];
       	int ans = 0;
        if (minv) ans = 1;
        else {
        	int cur = nums[0];
        	for (int i = 1; i < n; i++) {
        		if (cur == 0) {
        			ans++;
        			cur = nums[i];
        		}
        		else {
        			cur &= nums[i];
        		}
        	}
        	if (cur == 0) ans++;
        }
        return ans;
    }
};
#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
    	set<int> st;
    	int cnt = 0;
        for (int i = nums.size() - 1; i >= 0; i++) {
        	st.insert(nums[i]);
        	cnt++;
        	int success = true;
        	for (int j = 1; j <= k; j++) {
        		if (!st.count(j)) {
        			success = false;
        			break;
        		}
        	}
        	if (success) {
        		return cnt;
        	}
        }
        return 0;
    }
};
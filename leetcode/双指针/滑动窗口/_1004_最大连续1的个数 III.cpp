#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0;
        int res = 0;
        for(int j = 0; j < nums.size(); j++){
            if(nums[j] == 0) k--;
            while(k < 0){
                if(nums[i] == 0) k++;
                i++;
            }
            res = res > j - i + 1 ? res : j - i + 1;
        }
        return res;
    }
};
#include<vector>
using namespace std;

class Solution {
public:
    int averageValue(vector<int>& nums) {
        /*Given an integer array nums of 
        positive integers, return the average value of all even integers that are divisible by 3.*/
        int sum = 0, count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0 && nums[i] % 3 == 0) {
                sum += nums[i];
                count++;
            }
        }
        /*count may be zero*/
        if (count == 0) return 0;
        return sum / count;
    }
};
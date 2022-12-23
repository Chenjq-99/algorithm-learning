#include<iostream>
#include<vector>
using namespace std;
// https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;   
        while(left < right){
            if(numbers[left] + numbers[right] < target) left++;
            if(numbers[left] + numbers[right] > target) right--;
            if(numbers[left] + numbers[right] == target) break;
        }
        return vector<int>{left+1,right+1};
    }
};
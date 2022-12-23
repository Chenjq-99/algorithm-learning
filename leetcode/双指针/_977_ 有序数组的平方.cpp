#include<iostream>
#include<vector>
using namespace std;

// https://leetcode.cn/problems/squares-of-a-sorted-array/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // Ë«Ö¸Õë
        vector<int> result(nums.size(),0);
        int k = nums.size() - 1;
        int front = 0;
        int back = nums.size() - 1;
        while(front <= back){
            int frontSquares = nums[front] * nums[front];
            int backSquares = nums[back] * nums[back];
            if(frontSquares > backSquares){
                result[k--] = frontSquares;
                front++;
            }else{
                result[k--] = backSquares;
                back--;
            }
        }
        return result;
    }
};
#include<iostream>
#include<vector>
using namespace std;

// https://leetcode.cn/problems/spiral-matrix-ii/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int up = 0;
        int down = n - 1;
        int left = 0;
        int right = n - 1;
        int index = 1;
        vector<vector<int>> res(n,vector<int>(n,0));
        while(index <= n * n){
            for(int i = left; i <= right; i++){
            res[up][i] = index++;
            }
            up++;
            for(int i = up; i <= down; i++){
                res[i][right] = index++;
            }
            right--;
            for(int i = right; i >= left; i--){
                res[down][i] = index++;
            }
            down--;
            for(int i = down; i>= up; i--){
                res[i][left] = index++;
            }
            left++;
        }
        return res;
    }
};
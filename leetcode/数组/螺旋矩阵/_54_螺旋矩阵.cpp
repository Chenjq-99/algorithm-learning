#include<iostream>
#include<vector>
using namespace std;

// https://leetcode.cn/problems/spiral-matrix/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int column = matrix[0].size();
        int up = 0;
        int down = row - 1;
        int left = 0;
        int right = column - 1;
        vector<int> res;
        while(res.size() < row * column){
            for(int i = left; i <= right; i++){
                res.push_back(matrix[up][i]);
            }
            up++;
            if(res.size() >=  row * column) break;
            for(int i = up; i <= down; i++){
                res.push_back(matrix[i][right]);
            }
            right--;
            if(res.size() >=  row * column) break;
            for(int i = right; i >= left; i--){
                res.push_back(matrix[down][i]);
            }
            down--;
            if(res.size() >=  row * column) break;
            for(int i = down; i >= up; i--){
                res.push_back(matrix[i][left]);
            }
            left++;
        }
        return res;
    }
};
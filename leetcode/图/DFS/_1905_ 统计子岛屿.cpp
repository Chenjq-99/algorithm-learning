#include<iostream>
#include<vector>
using namespace std;

// https://leetcode.cn/problems/count-sub-islands/
class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int rows = grid1.size();
        int cols = grid1[0].size();
        int ans = 0;
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < cols; j++){
                    if(grid2[i][j] == 1){
                        if(dfs(grid1,grid2,i,j,rows,cols)) ans++;
                    }
                }
            }
        return ans;
    }

    bool dfs(vector<vector<int>>& grid1,vector<vector<int>>& grid2,int i,int j,int rows,int cols){
        if(i < 0 || i >= rows || j < 0|| j >=cols) return true;
        if(grid2[i][j] == 0) return true;
        bool flag = grid2[i][j] == grid1[i][j];
        grid2[i][j] = 0;
        bool flag_up = dfs(grid1,grid2,i-1,j,rows,cols);
        bool flag_down = dfs(grid1,grid2,i+1,j,rows,cols);
        bool flag_left = dfs(grid1,grid2,i,j-1,rows,cols);
        bool flag_right = dfs(grid1,grid2,i,j+1,rows,cols);
        return flag && flag_up && flag_down && flag_left && flag_right;
    }
};
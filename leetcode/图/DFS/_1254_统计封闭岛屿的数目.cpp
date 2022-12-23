#include<iostream>
#include<vector>
using namespace std;

// https://leetcode.cn/problems/number-of-closed-islands/
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                bool edge = i == 0 || i == rows - 1 || j == 0 || j == cols - 1;
                if(edge && grid[i][j] == 0){
                    dfs(grid,i,j,rows,cols);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 0){
                    ans++;
                    dfs(grid,i,j,rows,cols);
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<int>>& grid,int i,int j, int rows,int cols){
        if(i < 0 || i >= rows || j < 0 || j >= cols) return;
        if(grid[i][j] == 1) return;
        grid[i][j] = 1;
        dfs(grid,i-1,j,rows,cols);
        dfs(grid,i+1,j,rows,cols);
        dfs(grid,i,j-1,rows,cols);
        dfs(grid,i,j+1,rows,cols);
    }
};
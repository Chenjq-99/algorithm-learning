#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        int res = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                if(grid[i][j] == '1'){
                    res++;
                    dfs(grid, i, j, rows, columns);
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>& grid, int i, int j, int rows, int columns){
        if(i >= rows || i < 0 || j >= columns || j < 0) return; //越界
        if(grid[i][j] == '0') return; //遇到 0
        // 不是 0 把他淹没避免重复搜索
        grid[i][j] = '0';
        // 继续向四周搜索
        dfs(grid, i-1, j, rows, columns); //上
        dfs(grid, i+1, j, rows, columns); //下
        dfs(grid, i, j-1, rows, columns); //左
        dfs(grid, i, j+1, rows, columns); //右
    }

};
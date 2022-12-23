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
        if(i >= rows || i < 0 || j >= columns || j < 0) return; //Խ��
        if(grid[i][j] == '0') return; //���� 0
        // ���� 0 ������û�����ظ�����
        grid[i][j] = '0';
        // ��������������
        dfs(grid, i-1, j, rows, columns); //��
        dfs(grid, i+1, j, rows, columns); //��
        dfs(grid, i, j-1, rows, columns); //��
        dfs(grid, i, j+1, rows, columns); //��
    }

};
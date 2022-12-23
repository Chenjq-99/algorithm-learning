#include<vector>
#include<string>
using namespace std;

// https://leetcode.cn/problems/n-queens/
class Solution {
public:
    vector<vector<string>> result;
    bool isValid(int n, int row, int col, vector<string>& chessboard){
        // 检查列
        for(int i = 0; i < row; i++){
            if(chessboard[i][col] == 'Q'){
                return false;
            }
        }
        // 检查 45度角
        for (int i = row - 1, j = col - 1; i >=0 && j >= 0; i--, j--) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }
        // 检查 135度角
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }
        return true;

    }
    void placeQueen(int n, int row, vector<string>& chessboard){
        if(row == n){
            result.push_back(chessboard);
            return;
        }
        for(int col = 0; col < n; col++){
            if(isValid(n,row, col, chessboard)){
                chessboard[row][col] = 'Q';
                placeQueen(n,row+1,chessboard);
                chessboard[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> chessboard(n,string(n,'.'));
        placeQueen(n, 0, chessboard);
        return result;
    }
};
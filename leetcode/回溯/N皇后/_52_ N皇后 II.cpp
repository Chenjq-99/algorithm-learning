#include<iostream>
#include<string>
#include<vector>
using namespace std;

// https://leetcode.cn/problems/n-queens-ii/
class Solution {
public:
    int result = 0;
    bool isValid(int n, int row, int col, vector<string>& chessboard){
        // �����
        for(int i = 0; i < row; i++){
            if(chessboard[i][col] == 'Q'){
                return false;
            }
        }
        // ��� 45�Ƚ�
        for (int i = row - 1, j = col - 1; i >=0 && j >= 0; i--, j--) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }
        // ��� 135�Ƚ�
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }
        return true;

    }
    void placeQueen(int n, int row, vector<string>& chessboard){
        if(row == n){
            result++;
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
    int totalNQueens(int n) {
        vector<string> chessboard(n,string(n,'.'));
        placeQueen(n, 0, chessboard);
        return result;
    }
};
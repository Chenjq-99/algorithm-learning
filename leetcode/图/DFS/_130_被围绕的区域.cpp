#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                bool edge = i == 0 || i == rows - 1 || j == 0 || j == cols - 1;
                if(edge && board[i][j] == 'O'){
                    dfs(board, i, j, rows, cols);
                }
            }
        }
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }
    }
    void dfs(vector<vector<char>>& board, int i, int j, int rows, int cols){
        if(i >= rows || i < 0 || j >= cols || j < 0) return; //Խ��
        if(board[i][j] == 'X' || board[i][j] == '#') return; //���� X �����Ѿ����ʹ���O
        // �����ظ�����
        board[i][j] = '#';
        // ��������������
        dfs(board, i-1, j, rows, cols); //��
        dfs(board, i+1, j, rows, cols); //��
        dfs(board, i, j-1, rows, cols); //��
        dfs(board, i, j+1, rows, cols); //��
    }
};
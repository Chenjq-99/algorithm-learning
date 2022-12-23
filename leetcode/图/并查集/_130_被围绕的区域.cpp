#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    int n = 40005; // �ڵ�����
    int father[40005];
    // ���鼯��ʼ��
    void init() {
        for (int i = 0; i < n; ++i) {
            father[i] = i;
        }
    }
    // ���鼯��Ѱ���Ĺ���
    int find(int u) {
        return u == father[u] ? u : father[u] = find(father[u]);
    }
    // ��v->u �����߼��벢�鼯
    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return ;
        father[v] = u;
    }
    // �ж� u �� v�Ƿ��ҵ�ͬһ����
    bool same(int u, int v) {
        u = find(u);
        v = find(v);
        return u == v;
    }

public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        init();
        int dummy = rows * cols;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(board[i][j] == 'O'){
                    if(i == 0 || i == rows - 1 || j == 0 || j == cols - 1){
                        join(i * cols + j,dummy);
                    }else{
                        if(board[i - 1][j] == 'O' && i >0) join(i * cols + j,(i-1) * cols + j);
                        if(board[i + 1][j] == 'O' && i < rows - 1) join(i * cols + j,(i+1) * cols + j);
                        if(board[i][j - 1] == 'O' && j >0) join(i * cols + j,i * cols + j - 1);
                        if(board[i][j + 1] == 'O' && i < cols -1) join(i * cols + j,i * cols + j + 1);
                    }
                }
            }
        }
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(board[i][j] == 'O'){
                    if(!same(i * cols + j,dummy)) board[i][j] = 'X';
                }
            }
        }
    }
};
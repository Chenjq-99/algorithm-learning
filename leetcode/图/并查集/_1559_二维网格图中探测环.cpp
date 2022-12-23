#include<iostream>
#include<vector>
using namespace std;

// https://leetcode.cn/problems/detect-cycles-in-2d-grid/
class Solution {
private:
    int n = 250005; // �ڵ�����
    int father[250005];
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
    bool containsCycle(vector<vector<char>>& grid) {
        init();
        int rows = grid.size();
        int cols = grid[0].size();
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(i < rows -1 && grid[i][j] == grid[i+1][j]){
                    if(same(i*cols+j,(i+1)*cols+j)) return true;
                    join(i*cols+j,(i+1)*cols+j);
                }
                if(j < cols -1 && grid[i][j] == grid[i][j+1]){
                    if(same(i*cols+j,i*cols+j+1)) return true;
                    join(i*cols+j,i*cols+j+1);
                }
            }
        }
        return false;
    }
};
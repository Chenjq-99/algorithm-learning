#include<iostream>
#include<vector>
using namespace std;

// https://leetcode.cn/problems/detect-cycles-in-2d-grid/
class Solution {
private:
    int n = 250005; // 节点数量
    int father[250005];
    // 并查集初始化
    void init() {
        for (int i = 0; i < n; ++i) {
            father[i] = i;
        }
    }
    // 并查集里寻根的过程
    int find(int u) {
        return u == father[u] ? u : father[u] = find(father[u]);
    }
    // 将v->u 这条边加入并查集
    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return ;
        father[v] = u;
    }
    // 判断 u 和 v是否找到同一个根
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
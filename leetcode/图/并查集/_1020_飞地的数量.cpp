#include<iostream>
#include<vector>
using namespace std;

// https://leetcode.cn/problems/number-of-enclaves/
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
        if (u == v) return;
        father[v] = u;
    }
    // 判断 u 和 v是否找到同一个根
    bool same(int u, int v) {
        u = find(u);
        v = find(v);
        return u == v;
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        init();
        int rows = grid.size();
        int cols = grid[0].size();
        int dummy = rows * cols;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                bool edge = (i == 0 || i == rows - 1 || j == 0 || j == cols - 1);
                if(grid[i][j] == 1){
                    if(edge) join(i*cols+j,dummy);
                    else{
                        if(i > 0 && grid[i-1][j] == 1) join((i-1)*cols+j,i*cols+j);
                        if(i < rows - 1 && grid[i+1][j] == 1) join((i+1)*cols+j,i*cols+j);
                        if(j > 0 && grid[i][j-1] == 1) join(i*cols+j-1,i*cols+j);
                        if(j < cols - 1 && grid[i][j+1] == 1) join(i*cols+j+1,i*cols+j);
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 1 && !same(i*cols+j,dummy)) ans++;
            }
        }
        return ans;
    }
};
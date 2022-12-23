#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// https://leetcode.cn/problems/is-graph-bipartite/
// 这道题的思想和886题一模一样，将不喜欢的人union，看会不会有矛盾
class Solution {
private: 
    int n = 105;
    int parents[105];
    void init(){
        for(int i = 0; i < n; i++){
            parents[i] = i;
        }
    }
    int find(int i){
        return parents[i] == i ? i : find(parents[i]);
    }
    void join(int i, int j){
        int p1 = find(i);
        int p2 = find(j);
        if(p1 == p2) return;
        parents[p1] = p2;
    }
    bool same(int i, int j){
        return find(i) == find(j);
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        init();
        int m = graph.size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < graph[i].size(); j++){
                join(graph[i][0],graph[i][j]);
                if(same(i,graph[i][j])) return false;
            }
        }
        return true;
    }
};
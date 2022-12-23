#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

// https://leetcode.cn/problems/redundant-connection/

class Solution {
private:
    int n = 1005;
    int parents[10005];
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        init();
        for(vector<int> edge : edges){
            if(same(edge[0],edge[1])) return edge;
            join(edge[0],edge[1]);
        }
        return {};
    }
};
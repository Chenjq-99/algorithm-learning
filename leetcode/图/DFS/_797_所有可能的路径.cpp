#include<iostream>
#include<vector>
using namespace std;
// https://leetcode.cn/problems/all-paths-from-source-to-target/
// DFS + »ØËÝ
class Solution {
private:
    void dfs(int begin, int target, vector<vector<int>>& graph,vector<vector<int>>& result, vector<int>& path){
        if(begin == target){
            path.push_back(target);
            result.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(begin);
        for(auto i : graph[begin]){
            dfs(i, target, graph, result, path);
        }
        path.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        int target = graph.size() - 1;
        vector<int> path;
        dfs(0, target, graph, result, path);
        return result;
    }
};
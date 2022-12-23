#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<string, unordered_map<string,double>> graph;
    unordered_map<string,bool> visited;
    void dfs(string target, string begin, double pre, vector<double>& result, unordered_map<string,bool>& visited, int i){
        if(target == begin){
            result[i] = pre;
            return;
        }
        if(visited[begin]) return;
        visited[begin] = true;
        unordered_map<string,double> map = graph[begin];
        for(auto pair : map){
            if(result[i] == -1.0){
                dfs(target, pair.first, pre * pair.second, result, visited,i);
            }
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(int i = 0; i < values.size(); i++){
            graph[equations[i][0]][equations[i][1]] = values[i];
            graph[equations[i][1]][equations[i][0]] = 1 / values[i];
        }
        vector<double> result(queries.size(),-1.0);
        for(int i = 0; i < queries.size(); i++){
            if(graph.find(queries[i][0]) == graph.end() || graph.find(queries[i][1]) == graph.end()){
                continue;
            }
            visited.clear();
            dfs(queries[i][1],queries[i][0],1,result,visited,i);
        }
        return result;
    }
};
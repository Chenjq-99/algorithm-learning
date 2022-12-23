#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    unordered_map<int,vector<int>> outEdges;
    bool visited[200010];
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        for(auto v : edges){
            outEdges[v[0]].push_back(v[1]);
            outEdges[v[1]].push_back(v[0]);
        }
        return dfs(source, destination);
    }
    bool dfs(int source, int destination){
        if(source == destination) return true;
        vector<int> out = outEdges[source];
        if(out.size() == 0) return false;
        if(find(out.begin(),out.end(),destination) != out.end()) return true;
        visited[source] = true;
        for(int newSource : out){
            if(visited[newSource] == false && dfs(newSource,destination))
                return true;
        }
        return false;
    }
};
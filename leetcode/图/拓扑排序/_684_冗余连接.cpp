#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

// https://leetcode.cn/problems/redundant-connection/

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> inDegrees(n + 1);
        unordered_map<int,vector<int>> toVertices(n + 1);
        queue<int> queue;
        for(vector<int> edge : edges){
            inDegrees[edge[0]]++;
            inDegrees[edge[1]]++;
            toVertices[edge[0]].push_back(edge[1]);
            toVertices[edge[1]].push_back(edge[0]);
        }
        for(int i = 1; i <= n; i++){
            if(inDegrees[i] == 1) queue.push(i);
        }
        vector<bool> record(n+1,false);
        while(!queue.empty()){
            int vertex = queue.front();
            queue.pop();
            record[vertex] = true;
            for(int next : toVertices[vertex]){
                if(--inDegrees[next] == 1) queue.push(next);
            }  
        }
        for(int i = n - 1; i >= 0; i--){
            if(!record[edges[i][0]] && !record[edges[i][1]]) return edges[i];
        }
        return {1,2};
    }
};
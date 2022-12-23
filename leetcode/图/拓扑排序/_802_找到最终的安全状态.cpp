
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

// https://leetcode.cn/problems/find-eventual-safe-states/

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int size = graph.size();
        vector<int> outDegrees(size);
        vector<vector<int>> inEdges(size);
        for(int i = 0; i < size; i++){
            for(auto j : graph[i]){
                inEdges[j].push_back(i);
                outDegrees[i]++;
            }
        }
        queue<int> queue;
        for(int i = 0; i < size; i++){
            if(outDegrees[i] == 0) queue.push(i);
        }
        vector<int> result;
        while(!queue.empty()){
            int ans = queue.front();
            queue.pop();
            result.push_back(ans);
            for(auto i : inEdges[ans]){
                if(--outDegrees[i] == 0) queue.push(i);
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};
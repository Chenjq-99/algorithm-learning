#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

// https://leetcode.cn/problems/minimum-height-trees/

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(edges.size() == 0) return {0};
        vector<int> degrees(n,0);
        unordered_map<int,vector<int>> outEdges;
        for(auto edge : edges){
            degrees[edge[0]]++;
            degrees[edge[1]]++;
            outEdges[edge[0]].push_back(edge[1]);
            outEdges[edge[1]].push_back(edge[0]);
        }
        queue<int> queue;
        for(int i = 0; i < n; i++){
            if(degrees[i] == 1) queue.push(i);
        }
        int remain = n;
        while(remain > 2){
            int size = queue.size();
            remain -= size;
            for(int i = 0; i < size; i++){
                int front = queue.front();
                queue.pop();
                for(int next : outEdges[front]){
                    if(--degrees[next] == 1) queue.push(next);
                }
            }
        }
        return remain == 1 ? vector<int>{queue.front()} : vector<int>{queue.front(), queue.back()};
    }
};
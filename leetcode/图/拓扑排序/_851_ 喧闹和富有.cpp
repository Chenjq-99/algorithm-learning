#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

// https://leetcode.cn/problems/loud-and-rich/

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<int> inDegrees(n);
        vector<vector<int>> outEdges(n);
        for(auto v : richer){
            inDegrees[v[1]]++;
            outEdges[v[0]].push_back(v[1]);
        }
        queue<int> queue;
        for(int i = 0; i < n; i++){
            if(inDegrees[i] == 0) queue.push(i);
        }
        vector<int> answer(n);
        for(int i = 0; i < n; i++){
            answer[i] = i;
        }
        while(!queue.empty()){
            int person = queue.front();
            queue.pop();
            for(auto p : outEdges[person]){
                if(quiet[answer[person]] < quiet[answer[p]]) answer[p] = answer[person];
                if(--inDegrees[p] == 0) queue.push(p);
            }
        }
        return answer;
    }
};
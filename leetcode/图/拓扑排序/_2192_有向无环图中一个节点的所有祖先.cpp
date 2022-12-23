#include<vector>
#include<queue>
#include<set>
using namespace std;

// https://leetcode.cn/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/description/
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<set<int>> result(n);
        vector<vector<int>> graph(n);
        vector<int> inDegrees(n);
        for(auto edge : edges){
            graph[edge[0]].push_back(edge[1]);
            inDegrees[edge[1]]++;
        }
        queue<int> queue;
        for(int i = 0; i < n; i++){
            if(inDegrees[i] == 0) queue.push(i);
        }
        while(!queue.empty()){
            int cur = queue.front();
            queue.pop();
            for(int next : graph[cur]){
                result[next].insert(cur);
                result[next].insert(result[cur].begin(),result[cur].end());
                if(--inDegrees[next] == 0) queue.push(next);
            }
        }
        vector<vector<int>> answer;
        for(auto set : result){
            answer.push_back(vector<int>(set.begin(),set.end()));
        }
        return answer;
    }
};

#include<vector>
#include<queue>
using namespace std;
// https://leetcode.cn/problems/shortest-path-with-alternating-colors/
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>> graph(n);
        vector<vector<int>> visited(n,vector<int>(2,0));
        //0表示red 1表示blue
        for(auto& edge:redEdges){
            int from=edge[0];
            int to=edge[1];
            graph[from].push_back({to,0});
        }
        for(auto& edge:blueEdges){
            int from=edge[0];
            int to=edge[1];
            graph[from].push_back({to,1});
        }
        queue<vector<int>> q;
        vector<int> dis(n,INT32_MAX);
        dis[0]=0;
        q.push({0,0,1});//节点 距离 颜色
        q.push({0,0,0});
        while(!q.empty()){
            auto it=q.front();
            int from=it[0];
            int distance=it[1];
            int col=it[2];
            q.pop();
            for(auto& [to,colour]:graph[from]){
                if(colour==(!col) && !visited[to][colour]){
                    dis[to]=min(dis[to],distance+1);
                    q.push({to,distance+1,colour});
                    visited[to][colour]=1;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(dis[i]==INT_MAX)dis[i]=-1;
        }
        return dis;
    }
};
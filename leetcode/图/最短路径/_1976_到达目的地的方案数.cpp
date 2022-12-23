#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

// https://leetcode.cn/problems/number-of-ways-to-arrive-at-destination/discussion/    
class Solution {
private:
    vector<long> planNums;
    int MOD = 1e9 + 7;
    void dijkstra(vector<vector<pair<int,int>>>& graph, int start) {
        vector<long> dist(graph.size(), 2e11);
        dist[start] = 0;
        priority_queue<pair<long,int>, vector<pair<long,int>>, greater<>> pq;
        pq.emplace(0, start);
        while (!pq.empty()) {
            auto [dis, cur] = pq.top();
            pq.pop();
            if (dis > dist[cur]) continue;
            for (auto [next, weight] : graph[cur]) {
                long new_dis = dist[cur] + weight;
                if (new_dis < dist[next]) {
                    planNums[next] = planNums[cur] % MOD;
                    dist[next] = new_dis;
                    pq.emplace(new_dis, next);
                } else if (new_dis == dist[next]) {
                    planNums[next] += planNums[cur] % MOD;
                }
            }
        }
    }   
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        planNums.resize(n);
        planNums[0] = 1;
        vector<vector<pair<int,int>>> graph(n);
        for (auto& road : roads) {
            int v1 = road[0], v2 = road[1], time = road[2]; 
            graph[v1].emplace_back(v2, time);
            graph[v2].emplace_back(v1, time);
        }
        dijkstra(graph,0);
        return planNums[n-1] % MOD;
    }
};
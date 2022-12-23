#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

// https://leetcode.cn/problems/reachable-nodes-in-subdivided-graph/description/
class Solution {
private:
    vector<int> dijkstra(vector<vector<pair<int,int>>>& graph, int start) {
        vector<int> dist(graph.size(), INT_MAX);
        dist[start] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.emplace(0, start);
        while (!pq.empty()) {
            auto [dis, cur] = pq.top();
            pq.pop();
            if (dis > dist[cur]) continue;
            // ËÉ³Ú
            for (auto [next, weight] : graph[cur]) {
                int new_dis = dist[cur] + weight;
                if (new_dis < dist[next]) {
                    dist[next] = new_dis;
                    pq.emplace(new_dis, next);
                }
            }
        }
        return dist;
    }
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        // ½¨Í¼
        vector<vector<pair<int,int>>> graph(n);
        for (auto& edge : edges) {
            int v1 = edge[0], v2 = edge[1], wt = edge[2] + 1;
            graph[v1].emplace_back(v2, wt);
            graph[v2].emplace_back(v1, wt);
        }

        vector<int> dist = dijkstra(graph, 0);
        int res = 0;
        for_each(dist.begin(),dist.end(),[&](int ele){
            if(ele <= maxMoves) res++;
        });
        for (auto& edge : edges) {
            int v1 = edge[0], v2 = edge[1];
            int a = max(0, maxMoves - dist[v1]);
            int b = max(0, maxMoves - dist[v2]);
            res += min(a + b, edge[2]);
        }
        return res;
    }
};
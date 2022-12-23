#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

// ʹ�����ȼ�����
    /**
     * @description: 
     * @param {int} start ���
     * @param {vector<vector<pair<int,int>>>} graph ͼ [to, weight] = graph[from]
     * @return {vector<int>} dist ��㵽���������̾���
     */
    vector<int> dijkstra(vector<vector<pair<int,int>>>& graph, int start) {
        vector<int> dist(graph.size(), INT_MAX);
        dist[start] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.emplace(0, start);
        while (!pq.empty()) {
            auto [dis, cur] = pq.top();
            pq.pop();
            if (dis > dist[cur]) continue;
            // �ɳ�
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

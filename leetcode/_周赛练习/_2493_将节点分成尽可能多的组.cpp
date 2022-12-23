#include<vector>
#include<queue>
using namespace std;

// https://leetcode.cn/problems/divide-nodes-into-the-maximum-number-of-groups/
class Solution {
private:
    int n;
    vector<vector<int>> graph;
    // 颜色标记
    vector<int> color;
    // 记录dfs连通分量
    vector<int> nodes;
    // 用染色法记录是否是二分图
    bool dfs (int cur, int clr) {
        color[cur] = clr;
        nodes.push_back(cur);
        for (auto& nxt : graph[cur]) {
            // 同色 false
            if (color[nxt] == color[cur]) return false;
            // 反色 continue
            if (color[nxt] == (3 ^ clr)) continue;
            // 未染色， 是否能染上反色
            if (!dfs(nxt, 3 ^ clr)) return false;
        }
        return true;
    }
    // bfs返回连通分量最大层数
    int bfs(int cur) {
        vector<bool> vis(n + 1);

        queue<int> q;
        q.push(cur);
        vis[cur] = true;
        int level = 0;
        while (!q.empty()) {
            level += 1;
            int len = q.size();
            while (len--) {
                int from = q.front();
                q.pop();
                for (auto& to : graph[from]) {
                    if (vis[to] == false) {
                        q.push(to);
                        vis[to] = true;
                    }
                }
            }
        }
        return level;
    }
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        this->n = n;
        graph = vector<vector<int>>(n+1);
        color = vector<int>(n+1);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        int res = 0;
        for (int i = 1; i <= n; i++) {
            // 此联通分量已经处理过
            if (color[i] != 0) continue;
            // dfs该联通分量，并记录联通分量中的点
            nodes.clear();
            if (!dfs(i,1)) return -1; // 染色失败有奇数环
            // 联通分量收集成功
            int maxlevels = 0; // 该联通分量最大层数
            for (auto& x : nodes) { // 以每一个点为起点计算层数
                maxlevels = max(maxlevels, bfs(x));
            }
            res += maxlevels;
        }
        return res;
    }
};
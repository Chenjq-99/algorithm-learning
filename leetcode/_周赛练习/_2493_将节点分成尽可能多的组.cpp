#include<vector>
#include<queue>
using namespace std;

// https://leetcode.cn/problems/divide-nodes-into-the-maximum-number-of-groups/
class Solution {
private:
    int n;
    vector<vector<int>> graph;
    // ��ɫ���
    vector<int> color;
    // ��¼dfs��ͨ����
    vector<int> nodes;
    // ��Ⱦɫ����¼�Ƿ��Ƕ���ͼ
    bool dfs (int cur, int clr) {
        color[cur] = clr;
        nodes.push_back(cur);
        for (auto& nxt : graph[cur]) {
            // ͬɫ false
            if (color[nxt] == color[cur]) return false;
            // ��ɫ continue
            if (color[nxt] == (3 ^ clr)) continue;
            // δȾɫ�� �Ƿ���Ⱦ�Ϸ�ɫ
            if (!dfs(nxt, 3 ^ clr)) return false;
        }
        return true;
    }
    // bfs������ͨ����������
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
            // ����ͨ�����Ѿ������
            if (color[i] != 0) continue;
            // dfs����ͨ����������¼��ͨ�����еĵ�
            nodes.clear();
            if (!dfs(i,1)) return -1; // Ⱦɫʧ����������
            // ��ͨ�����ռ��ɹ�
            int maxlevels = 0; // ����ͨ����������
            for (auto& x : nodes) { // ��ÿһ����Ϊ���������
                maxlevels = max(maxlevels, bfs(x));
            }
            res += maxlevels;
        }
        return res;
    }
};
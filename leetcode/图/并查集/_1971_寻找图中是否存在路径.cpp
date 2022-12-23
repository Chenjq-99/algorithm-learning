#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
private:
    int n = 200005; // �ڵ�����
    int father[200005];
    // ���鼯��ʼ��
    void init() {
        for (int i = 0; i < n; ++i) {
            father[i] = i;
        }
    }
    // ���鼯��Ѱ���Ĺ���
    int find(int u) {
        return u == father[u] ? u : father[u] = find(father[u]);
    }
    // ��v->u �����߼��벢�鼯
    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        father[v] = u;
    }
    // �ж� u �� v�Ƿ��ҵ�ͬһ����
    bool same(int u, int v) {
        u = find(u);
        v = find(v);
        return u == v;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        init();
        for(vector<int> edge : edges){
            join(edge[0],edge[1]);
        }
        return same(source,destination);
    }
};

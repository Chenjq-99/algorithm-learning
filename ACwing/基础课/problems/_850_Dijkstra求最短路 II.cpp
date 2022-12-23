#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

typedef pair<int, int> PII;

const int N = 150010;

int n, m;
int h[N], w[N], e[N], nxt[N], idx;
int dist[N];
bool st[N];

void add(int x, int y, int z) {
    e[idx] = y;
    w[idx] = z;
    nxt[idx] = h[x];
    h[x] = idx++;
}
int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});
    while (heap.size()) {
        auto t = heap.top();
        heap.pop();               
        int ver = t.second, dis = t.first;
        if (st[ver]) continue;
        st[ver] = true;
        for (int i = h[ver]; i != -1; i = nxt[i]) {
            int j = e[i];
            if (dis + w[i] < dist[j]) {
                dist[j] = dis + w[i];
                heap.push({dist[j], j});
            }
        }
    }
    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];    
}

int main() {
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while (m--) {
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
    }
    cout<< dijkstra() << endl;
    return 0;
}
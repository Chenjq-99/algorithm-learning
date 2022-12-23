#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

const int N = 150010;

int n, m;
int h[N], w[N], e[N], nxt[N], idx;
int dist[N];
bool st[N]; // st[i]表示i是否在队列中

void add(int x, int y, int z) {
    e[idx] = y;
    w[idx] = z;
    nxt[idx] = h[x];
    h[x] = idx++;
}
void spfa() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    st[1] = true;
    while (q.size()) {
        int t = q.front();
        q.pop();
        st[t] = false;
        for (int i = h[t]; i != -1; i = nxt[i]) {
            int j = e[i];
            // 如果j能被更新，那么j后边的点才有可能被更新
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                if (!st[j]) { // j 不在队列里，才把 j 加入队列
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }  
    if (dist[n] == 0x3f3f3f3f) cout << "impossible" <<endl;
    else cout << dist[n] <<endl;
}

int main() {
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while (m--) {
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
    }
    spfa();
    return 0;
}
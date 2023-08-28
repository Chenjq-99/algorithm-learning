#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int inf = 0x3f3f3f3f;

const int N = 25010, M = 200010;
int t, r, p, s;
int h[N], e[M], ne[M], w[M], idx;

vector<int> blocks[N];
int bid[N];
int indgree[N];
int cnt;

int dist[N];
bool st[N];

queue<int> q;

void add(int a, int b, int c) 
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u, int id)
{
    blocks[id].push_back(u);
    bid[u] = id;
    for (int i = h[u]; ~i; i = ne[i]) 
    {
        int j = e[i];
        if (!bid[j]) dfs(j, id);
    }
}

void dijkstra(int id) 
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    for (auto& u : blocks[id])
    {
        pq.emplace(dist[u], u);
    }
    while (pq.size())
    {
        auto t = pq.top();
        pq.pop();

        int ver = t.second;
        if (st[ver]) continue;
        st[ver] = true;

        for (int i = h[ver]; ~i; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[ver] + w[i])
            {
                dist[j] = dist[ver] + w[i];
                if (bid[j] == id) pq.emplace(dist[j], j);
            }
            if (bid[j] != id && --indgree[bid[j]] == 0) 
                q.push(bid[j]);
        }
    }
}

void topoSort()
{
    memset(dist, 0x3f, sizeof dist);
    dist[s] = 0;
    
    for (int i = 1; i <= cnt; i++)
    {
        if (indgree[i] == 0) q.push(i);
    }

    while (q.size())
    {
        int t = q.front();
        q.pop();
        dijkstra(t);
    }

}

int main()
{
    cin >> t >> r >> p >> s;
    memset(h, -1, sizeof h);
    for (int i = 0; i < r; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    for (int i = 1; i <= t; i++)
    {
        if (!bid[i]) 
        {
            dfs(i, ++cnt);
        }
    }
    for (int i = 0; i < p; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        indgree[bid[b]]++;
    }
    topoSort();
    for (int i = 1; i <= t; i++)
    {
        if (dist[i] >= inf / 2) puts("NO PATH");
        else printf("%d\n", dist[i]);
    }
    return 0;
}
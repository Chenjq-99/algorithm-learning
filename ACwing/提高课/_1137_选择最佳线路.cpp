#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

const int N = 1010, M = 21010;

int n, m, s;
int h[N], e[M], ne[M], w[M], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    memset(st, false, sizeof st);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.emplace(0, 0);
    dist[0] = 0;
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
                pq.emplace(dist[j], j);
            }
        }
    }
}

void solve()
{
    memset(h, -1, sizeof h);
    while (m--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int a;
        scanf("%d", &a);
        add(0, a, 0);
    }
    dijkstra();
    if (dist[s] == 0x3f3f3f3f) printf("%d\n", -1);
    else printf("%d\n", dist[s]);
}
int main()
{
    while (scanf("%d%d%d", &n, &m, &s) != -1) solve();
    return 0;
}
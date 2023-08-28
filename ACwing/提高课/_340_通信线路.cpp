#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int N = 1010, M = 20010;
int n, p, k;
int h[N], e[M], ne[M], w[M],idx;
int dist[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool check(int limit)
{
    memset(dist, 0x3f, sizeof dist);
    memset(st, false, sizeof st);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.emplace(0, 1);
    dist[1] = 0;
    while (pq.size())
    {
        auto t = pq.top();
        pq.pop();
        int ver = t.second;
        if (st[ver]) continue;
        st[ver] = true;
        for (int i = h[ver]; ~i; i = ne[i])
        {
            int j = e[i], d = w[i] > limit;
            if (dist[j] > dist[ver] + d)
            {
                dist[j] = dist[ver] + d;
                pq.emplace(dist[j], j);
            }
        }
    }
    return dist[n] <= k;
}

int main()
{
    scanf("%d%d%d", &n, &p, &k);
    memset(h, -1, sizeof h);
    for (int i = 0; i < p; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c), add(b, a, c);
    }
    int l = 0, r = 1e6 + 1;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    if (r == 1e6 + 1) r = -1;
    printf("%d\n", r);
    return 0;
}

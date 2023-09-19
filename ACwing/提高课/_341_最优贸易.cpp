#include<bits/stdc++.h>
using namespace std;

const int N = 100010, M = 1000010;

int n, m;
int h[N], rh[N], e[M], ne[M], w[N], idx;
int dmax[N], dmin[N];
bool st[N];

void add(int h[], int a, int b)
{
    e[idx] = b; ne[idx] = h[a], h[a] = idx++;
}

void spfa(int h[], int dist[], int direct)
{
    queue<int> q;
    if (direct == 1)
    {
        memset(dmin, 0x3f, sizeof dmin);
        memset(st, false, sizeof st);
        dist[1] = w[1], st[1] = true;
        q.push(1);
    }
    else
    {
        memset(dmax, -0x3f, sizeof dmax);
        memset(st, false, sizeof st);
        dist[n] = w[n], st[n] = true;
        q.push(n);git
    }
    while (q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = false;
        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if (direct == 1)
            {
                if (dist[j] > min(dist[t], w[j]))
                {
                    dist[j] = min(dist[t], w[j]);
                    if (!st[j])
                    {
                        q.push(j);
                        st[j] = true;
                    }
                }
            }
            else
            {
                if (dist[j] < max(dist[t], w[j]))
                {
                    dist[j] = max(dist[t], w[j]);
                    if (!st[j])
                    {
                        q.push(j);
                        st[j] = true;
                    }
                }
            }
        }
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
    memset(h, -1, sizeof h);
    memset(rh, -1, sizeof rh);

    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        add(h, x, y), add(rh, y, x);
        if (z == 2) add(h, y, x), add(rh, x, y);
    }
    spfa(h, dmin, 1);
    spfa(rh, dmax, 2);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, dmax[i] - dmin[i]);
    }
    printf("%d\n", ans);
    return 0;
}
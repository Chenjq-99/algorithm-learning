#include<bits/stdc++.h>
using namespace std;

const int N = 510, P = 810, M = 1450 * 2 + 10;

int n, p, m;
int h[P], e[M], ne[M], w[M], idx;
int ids[N];
int dist[P];
bool st[P];

int spfa(int u) 
{
    memset(dist, 0x3f, sizeof dist);
    memset(st, false, sizeof st);
    queue<int> q;
    q.emplace(u);
    dist[u] = 0, st[u] = true;

    while (q.size())
    {
        auto t = q.front();
        q.pop();
        st[t] = false;
        
        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                if (!st[j])
                {
                    q.emplace(j);
                    st[j] = true;
                }
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++) 
    {
        if (dist[ids[i]] == 0x3f3f3f3f) return 0x3f3f3f3f;
        res += dist[ids[i]];
    }

    return res;
}
void add(int a, int b, int c) 
{
    e[idx] = b, w[idx] = c; ne[idx] = h[a], h[a] = idx++;
}
int main()
{
    cin >> n >> p >> m;

    for (int i = 1; i <= n; i++)
        cin >> ids[i];

    memset(h, -1, sizeof h);
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }

    int res = 0x3f3f3f3f;

    for (int i = 1; i <= p; i++)
    {
        res = min(res, spfa(i));
    }

    cout << res << endl;

    return 0;
}
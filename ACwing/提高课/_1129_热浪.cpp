#include<bits/stdc++.h>
using namespace std;

const int N = 2510, M = 6210 * 2;

int n, m, S, T;
int h[N], e[M], ne[M], w[M], idx;
int dist[N];
bool st[N];

void spfa() 
{
    memset(dist, 0x3f, sizeof dist);
    queue<int> q;
    q.emplace(S);
    dist[S] = 0, st[S] = true;
    while (q.size())
    {
        auto t = q.front();
        q.pop();
        st[t] = false;
        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if (dist[t] + w[i] < dist[j])
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
}

void add(int a, int b, int c) 
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
int main()
{
    cin >> n >> m >> S >> T;
    
    memset(h, -1, sizeof h);
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }

    spfa();

    cout << dist[T] << endl;

    return 0;
}
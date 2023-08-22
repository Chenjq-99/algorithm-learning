#include<bits/stdc++.h>
using namespace std;

const int N = 2010;

int n, m, S, T;
double g[N][N];
double dist[N];
bool st[N];

void dijkstra() 
{
    dist[S] = 0;

    int t = -1;
    for (int i = 1; i <= n; i++)
    {
        if (!st[i] || (t == -1 || dist[i] < dist[t]))
        {
            t = i;
        }
    }
    st[t] = true;

    for (int i = 1; i <= n; i++)
    {
        if (dist[i] < dist[t] * g[t][i])
        {
            dist[i] = dist[t] * g[t][i];
        }
    }
}
int main()
{
    cin >> n >> m;

    while (m--) 
    {
        int a, b, c;
        cin >> a >> b >> c;
        double z = (100 - c) / 100.;
        g[a][b] = g[b][a] = z;
    }

    cin >> S >> T;

    dijkstra();

    cout << 100 / dist[T] << endl;

    return 0;
}
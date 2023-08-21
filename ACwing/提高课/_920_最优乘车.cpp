#include<bits/stdc++.h>
using namespace std;

const int N = 510;

int n, m;
bool g[N][N];
int stops[N];
int dist[N];

void bfs()
{
    memset(dist, 0x3f, sizeof dist);

    queue<int> q;
    q.emplace(1);
    dist[1] = 0;

    while (q.size())
    {
        auto t = q.front();
        q.pop();

        for (int i = 1; i <= n; i++) {
            if (g[t][i] && dist[i] > dist[t] + 1)
            {
                q.emplace(i);
            }
        }
    }
}

int main()
{
    cin >> m >> n;

    for (int i = 1; i <= m; i++)
    {
        string line;
        getline(cin, line);
        stringstream ssin(line);
        int p, cnt = 0;
        while (ssin >> p)
        {
            stops[cnt++] = p;
        }
        for (int i = 1; i <= cnt; i++)
            for (int j = i + 1; j <= cnt; j++)
            {
                g[i][j] = true;
            }
        
        bfs();

        if (dist[n] == 0x3f3f3f3f) puts("NO");
        else cout << max(0, dist[n] - 1) << endl;

        return 0;
    }
}

#include<bits/stdc++.h>
using namespace std;

const int N = 110;

int n, m;
int dist[N][N];

int main()
{
    cin >> n >> m;

    memset(dist, 0x3f, sizeof dist);
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = dist[b][a] = c;
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    int res = 0;
    for (int i = 1; i <= n; i++)
        if (dist[1][i] == 0x3f3f3f3f)
        {
            res = -1;
            break;
        }
        else
        {
            res = max(res, dist[1][i]);
        }

    cout << res << endl;
    return 0;
}

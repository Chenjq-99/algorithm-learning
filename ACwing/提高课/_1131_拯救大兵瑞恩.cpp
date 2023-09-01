#include<bits/stdc++.h>
using namespace std;

const int N = 12, M = N * N, P = 1 << 12;

int doors[M][M], walls[M][M], keys[M];
int ids[N][N];
int dist[M][P];
bool st[M][P];

int n, m, p, k, s, id;

int bfs() {
    memset(dist, 0x3f, sizeof dist);
    memset(st, false, sizeof st);
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
    deque<array<int, 3>> q;
    q.push_back({1, 1, 0});
    dist[1][0] = 0;
    while (q.size())
    {
        auto t = q.front();
        q.pop_front();
        int x = t[0], y = t[1], state = t[2];
        int a = ids[x][y];
        if (st[a][state]) continue;
        st[a][state] = true;
        if (x == n && y == m) return dist[a][state];
        if (keys[a]) 
        {
            if (dist[a][state | keys[a]] > dist[a][state]) {
                dist[a][state | keys[a]] = dist[a][state];
                q.push_front({x, y, state | keys[a]}); 
            }
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx > n || nx <= 0 || ny > m || ny <= 0) continue;
            int  b = ids[nx][ny];
            if (walls[a][b] || doors[a][b] && (doors[a][b] & state) == 0) continue;
            if (dist[b][state] > dist[a][state] + 1)
            {
                dist[b][state] = dist[a][state] + 1;
                q.push_back({nx, ny, state});
            }
        }
    }
    return -1;
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &p, &k);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            ids[i][j] = ++id;
    while (k--)
    {
        int x1, y1, x2, y2, c;
        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &c);
        int a = ids[x1][y1], b = ids[x2][y2];
        if (c) doors[a][b] = doors[b][a] = 1 << c;
        else walls[a][b] = walls[b][a] = 1;
    }
    scanf("%d", &s);
    while (s--)
    {
        int x, y, c;
        scanf("%d%d%d", &x, &y, &c);
        keys[ids[x][y]] |= 1 << c;
    }
    printf("%d\n", bfs());
    return 0;
}
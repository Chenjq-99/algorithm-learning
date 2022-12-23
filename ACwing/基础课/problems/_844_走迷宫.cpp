#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

typedef pair<int, int> PII;

const int N = 10;
int m, n;
int g[N][N]; // 图
int d[N][N]; //每个点到起点的距离
PII q[N * N]; //模拟队列

int bfs() {
    int hh = 0, tt = 0;
    q[0] = {0, 0};

    memset(d, -1, sizeof d);
    d[0][0] = 0;

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    while (hh <= tt) {
        auto t = q[hh++];
        for (int i = 0; i < 4; i++) {
            int x = t.first + dx[i], y = t.second + dy[i];
            if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1) {
                d[x][y] = d[t.first][t.second] + 1;
                q[++tt] = {x, y};
            }
        }
    }
    return d[n - 1][m -1];
}
int main (){
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &g[i][j]);
        }
    }

    printf("%d", bfs());
    return 0;
} 
// https://www.acwing.com/problem/content/1127/
#include <bits/stdc++.h>

#define x first 
#define y second

typedef std::pair<double, double> pdd;

const int N = 155;
const double INF = 1e20;

int n;
pdd node[N];
char g[N][N];
double dist[N][N], maxd[N];

double get_dist(pdd a, pdd b) {
    double dx = a.x - b.x, dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> node[i].x >> node[i].y;
    }
    for (int i = 0; i < n; i++) {
        std::cin >> g[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                dist[i][j] == 0.0;
            } else if (g[i][j] == '1') {
                dist[i][j] = get_dist(node[i], node[j]);
            } else {
                dist[i][j] = INF;
            }
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = std::min(dist[i][j], 
                dist[i][k] + dist[k][j]);
            }
        }
    }
    double res1 = 0.0, res2 = INF;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] < INF / 2) {
                maxd[i] = std::max(maxd[i], dist[i][j]);
            }
        }
        res1 = std::max(res1, maxd[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] > INF / 2) {
                res2 = std::min(res2, 
                get_dist(node[i], node[j]) + maxd[i] + maxd[j]);
            }
        }
    }
    std::cout.setf(std::ios::fixed, std::ios::floatfield);
    std::cout << std::setprecision(6) << std::max(res1, res2) << std::endl;
    return 0;
}
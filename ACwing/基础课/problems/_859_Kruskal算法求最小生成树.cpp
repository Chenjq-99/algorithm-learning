#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100010, M = 200010;

int p[N];
int n, m;

struct Edge {
    int a, b, w;
} edges[M];

int find(int x) {
    return x == p[x] ? p[x] : p[x] = find(p[x]);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = {a, b, w};
    }
    sort(edges, edges + m, [&](Edge& e1, Edge& e2){return e1.w < e2.w;});
    for (int i = 1; i <= n; i++) p[i] = i;
    int res = 0, cnt = 0;
    for (int i = 0; i < m; i++) {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        a = find(a), b = find(b);
        if (a != b) {
            p[a] = b;
            res += w;
            cnt++;
        }
    }
    if (cnt < n - 1) cout << "impossible" << endl;
    else cout << res << endl;
    return 0;
}
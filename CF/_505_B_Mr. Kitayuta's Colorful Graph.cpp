#include<bits/stdc++.h>
using namespace std;

const int N = 105;

int m, n, q;
int h[N][N], e[N][N], ne[N][N], idx[N];
bool st[N];

void add(int a, int b, int c) {
    e[c][idx[c]] = b, ne[c][idx[c]] = h[c][a], h[c][a] = idx[c]++;
}
int main() {
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
        add(b, a, c);
    }

    scanf("%d", &q);
    while (q--) {
        int a, b, cnt = 0;
        scanf("%d%d", &a, &b);
        for (int c = 1; c <= m; c++) {
            queue<int> q;
            q.push(a);
            bool success = false;
            memset(st, false, sizeof st);
            while(!q.empty()) {
                int t = q.front();
                q.pop();
                if (t == b) {
                    cnt++;
                    success = true;
                    break;
                }
                st[t] = true;
                for (int i = h[c][t]; i != -1; i = ne[c][i]) {
                    int j = e[c][i];
                    if (st[j]) continue;                    
                    q.push(j);
                }
                if (success) break;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}

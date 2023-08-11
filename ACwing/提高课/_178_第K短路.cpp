#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include<vector>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 1010, M = 10010;

int n, m;
int S, T, K;
int h[N], rh[N], e[M], ne[M], w[M], idx;
int real_dist[N], heur_dist[N];
int cnt[N];

void add(int h[], int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void getHeuristicDistance() {
    
    memset(heur_dist, 0x3f, sizeof heur_dist);
    heur_dist[T] = 0;

    priority_queue<PII, vector<PII>, greater<PII>> q;

    q.emplace(0, T);


    while (q.size()) {
        auto t  = q.top();
        q.pop();

        int ver = t.y, distance = t.x;
        if (distance >= heur_dist[ver]) continue;

        for (int i = rh[ver]; ~i; i = ne[i]) {
            int j = e[i];
            if (heur_dist[j] > distance + w[i]) {
                heur_dist[j] = distance + w[i];
                q.emplace(heur_dist[j], j);
            }
        }
    }
}

int getScore(int x) {
    return real_dist[x] + heur_dist[x];
}
void A_star() {

    memset(real_dist, 0x3f, sizeof real_dist);
    real_dist[S] = 0;

    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.emplace(getScore(S), S);

    while (q.size()) {
        auto t = q.top();
        q.pop();

        int ver = t.y;
        cnt[ver]++;
        if (cnt[T] == K) break;

        for (int i = h[ver]; ~i; i = ne[i]) {
            int j = e[i];
            if (cnt[j] < K) {
                real_dist[j] = real_dist[ver] + w[i];
                q.emplace(getScore(j), j);
            }
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        add(h, a, b, c);
        add(rh, b, a, c);
    }
    scanf("%d%d%d", &S, &T, &K);

    getHeuristicDistance();

    for (int i = 0; i < n; i++) printf("%d\n", heur_dist[i]);

    A_star();

    if (real_dist[T] == 0x3f3f3f3f) puts("-1");
    else printf("%d", real_dist[T]);

    return 0;
}


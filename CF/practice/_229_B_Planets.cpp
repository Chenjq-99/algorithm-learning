/*
https://codeforces.com/contest/229/problem/B

���� n(2��n��1e5) m(0��m��1e5) ��ʾһ�� n �� m �ߵ�����ͼ���ڵ��Ŵ� 1 ��ʼ����
Ȼ������ m ���ߣ�ÿ���߰��� 3 ���� a b c(1��c��1e4)����ʾ��һ����ȨΪ c ����������� a �� b����ʾ�� a �� b ��Ҫ c �롣
��֤���Ի������رߡ�
Ȼ������ n �У�ÿ�е�һ���� k ��ʾ���� t[i] �ĳ��ȣ�Ȼ���������� t[i]��
���� t[i] ��һ���ϸ�������У�0��t[i][j]<1e9��
���� k ֮�� ��1e5��

��ʼʱ��Ϊ 0����� 1 ������Ҫȥ n��
������ڵ� i�����ǵ�ǰʱ�������� t[i] �У���ô�����ȴ� 1 �롣�����һ����Ȼ�� t[i] �У���ô�����ȴ� 1 �롣�������ơ�
������� n ������ʱ�䡣
����޷����� n����� -1��
*/

/*
https://codeforces.com/contest/229/submission/206931343

Dijkstra �ı��Ρ�
�� dis[i] ����ɿ��Դ� i ����������ʱ�䡣�ر�أ�dis[n] ����ɵ� n ������ʱ�䡣
������ʱ�� j ����� i����ô��Ҫ������� >= j �ĵ�һ������ t[i] �е��� next�����԰����ڵ�ʱ��ϲ������䣬�������־������ next��

�״�㣺
1. t[1][0] = 0 �������������
2. t[n] �е����ݲ�Ӧ�����ǡ�
*/
#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;
const int N = 100010, M = 200010;

int h[N], e[M], ne[M], w[M], idx;

int n, m, k, dist[N];
// dist[i]��1��i��̵�ʱ�䣬����i�뿪����̵�ʱ��

bool st[N];

struct Range {
    int l, r;
};

vector<vector<Range>> ranges(N);

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int getStartTime(int u, int t) {
    int l = 0, r = ranges[u].size() - 1;
    while (l < r) {
        int mid = l + r >> 1;
        if (ranges[u][mid].r >= t) r = mid;
        else l = mid + 1;
    }
    if (l < ranges[u].size() && ranges[u][l].r >= t) {
        if (ranges[u][l].l <= t) {
            t = ranges[u][l].r + 1;
        }
    }
    return t;
}
void dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    memset(st, false, sizeof st);
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    dist[1] = getStartTime(1, 0);
    pq.push({dist[1], 1});
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if(st[u]) continue;
        st[u] = true;
        for (int i = h[u]; i != -1; i = ne[i]) {
            int j = e[i];
            int d = dist[u] + w[i];
            if (j != n) d = getStartTime(j, d);
            if (d < dist[j]) {
                dist[j] = d;
                pq.push({d, j});
            }
        }
    }
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
    for (int i = 1; i <= n; i++) {
        scanf("%d", &k);
        int pre = -2, t = 0;
        while (k--) {
            scanf("%d", &t);
            if (t > pre + 1) {
                ranges[i].push_back({t, t});
            } else {
                ranges[i].back().r = t;
            }
            pre = t;
        }
    }
    dijkstra();
    if (dist[n] > 0x3f3f3f3f / 2) printf("%d\n", -1);
    else printf("%d", dist[n]);
    return 0;
}
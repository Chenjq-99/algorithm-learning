#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
typedef pair<int, int> pii;

const int inf = 0x3f3f3f3f3f;

const int N = 50010;

int n, m;
array<int, 6> source;
vector<pii> g[N];
vector<int> dist[7];
vector<bool> st;
int ans = inf;

void dijkstra(int u, vector<int>& dist) {
    dist.reserve(n + 1);
    fill(dist.begin(), dist.end(), inf);
    fill(st.begin(), st.end(), false);
    dist[u] = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.emplace(u);
    while (pq.size())
    {
        int t = pq.top();
        pq.pop();
        if (st[t]) continue;
        st[t] = true;
        for (auto& p : g[t]) {
            int j = p.x, w = p.y;
            if (dist[j] > dist[t] + w) {
                dist[j] = dist[t] + w;
                pq.emplace(j);
            }
        }
    }
}

void dfs(int u, int cnt, int d) {
    if (cnt == 6) {
        ans = min(ans, d);
        return;
    } 
    for (int i = 1; i <= 6; i++) {
        if (!st[i] && i != u) {
            st[i] = true;
            dfs(i, cnt + 1, d + dist[u][i]);
            st[i] = false;
        }
    }

}
int main() {
    cin >> n >> m;
    source[0] = 1;
    for (int i = 1; i <= 5; i++) cin >> source[i];
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }
    st.reserve(n + 1);
    for (int i = 0; i <= 5; i++)
        dijkstra(source[i], dist[source[i]]);
    fill(st.begin(), st.end(), false);
    dfs(1, 0, 0);
    cout << ans << endl;
}



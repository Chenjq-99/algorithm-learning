#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

const int N = 150010;

int n, m;
int h[N], w[N], e[N], nxt[N], idx;
int dist[N], cnt[N];
bool st[N];

void add(int x, int y, int z) {
    e[idx] = y;
    w[idx] = z;
    nxt[idx] = h[x];
    h[x] = idx++;
}
bool spfa() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    queue<int> q;
    // ��������Ҹ�����������1�ܵ���ĸ�������ˣ���Ҫ�����е㶼���뵽������
    for (int i = 1; i <= n; i++) {
        q.push(i);
        st[i] = true;
    } 
    while (q.size()) {
        int t = q.front();
        q.pop();
        st[t] = false;
        for (int i = h[t]; i != -1; i = nxt[i]) {
            int j = e[i];
            // ���j�ܱ����£���ôj��ߵĵ���п��ܱ�����
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] >= n) return true;
                if (!st[j]) { // j ���ڶ�����Ű� j �������
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }  
    return false;
}

int main() {
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while (m--) {
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
    }
    if(spfa()) puts("Yes");
    else puts("No");
    return 0;
}
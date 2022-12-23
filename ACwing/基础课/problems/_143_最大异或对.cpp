#include<iostream>
using namespace std;

const int N = 100010, M = 31 * N;
int son[M][2], q[N], n, idx;

void insert (int x) {
    int p = 0;
    for (int i = 30; i >= 0; --i) {
        int u = (x >> i) & 1;
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
}
// 查找和x做异或最大的数
int query (int x) {
    int p = 0;
    int res = 0;
    for (int i = 30; i >= 0; --i) {
        int u = (x >> i) & 1;
        if (son[p][!u]) u = !u;
        p = son[p][u];
        res = (res << 1) + u;
    }
    return res;
}
int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &q[i]);
    int res = 0;
    for (int i = 0; i < n; i++) {
        insert(q[i]);
        int x = query(q[i]);
        res = max(res, q[i] ^ x);
    }
    printf("%d", res);
    return 0;
}

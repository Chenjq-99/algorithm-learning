// https://codeforces.com/problemset/problem/1139/C

/*

输入 n(2≤n≤1e5) k(2≤k≤100) 和一棵无向树的 n-1 条边（节点编号从 1 开始），每条边包含 3 个数 x y c，
表示有一条颜色为 c 的边连接 x 和 y，其中 c 等于 0 或 1。

对于长为 k 节点序列 a，走最短路，按顺序经过节点 a1 -> a2 -> ... -> ak。
对于所有长为 k 的节点序列 a（这有 n^k 个），统计至少经过一条 c=1 的边的序列 a 的个数。
*/

/*
正难则反，统计只经过 c=0 的序列数。
相当于计算每个 c=0 组成的连通块的大小 sz，对应的只经过 c=0 序列数为 sz^k。
答案为 n^k - ∑sz^k，用快速幂计算。
*/
#include<bits/stdc++.h>

using namespace std;

const int N = 100010, MOD = 1e9 + 7;
int p[N], h[N];
int n, k;

int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
}

int qmi(int a, int b, int p) {
    int res = 1;
    while (b) {
        if (b & 1) res = (long long)res * a % p;
        b >>= 1;
        a = (long long)a * a % p;
    }
    return res;
}
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        if (!c) {
            p[find(u)] = find(v);
        }
    }
    for (int i = 1; i <= n; i++) {
        h[find(i)]++;
    }
    int ans = qmi(n, k, MOD);
    for (int i = 1; i <= n; i++) {
        ans = (ans - qmi(h[i], k, MOD) + MOD) % MOD;
    }
    printf("%d\n", ans);
    return 0;
}
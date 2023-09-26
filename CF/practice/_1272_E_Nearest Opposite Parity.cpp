/*

https://codeforces.com/problemset/problem/1272/E

输入 n(≤2e5) 和长为 n 的数组 a(1≤a[i]≤n)，下标从 1 开始。

从位置 i，你可以移动到位置 i-a[i] 或者 i+a[i]，移动后的位置必须在 [1,n] 内。
定义 d(i) 表示从位置 i 出发，移动到某个位置 j 的最小移动次数，要求 a[i] 和 a[j] 的奇偶性不同。如果不存在这样的 j，则 d(i) 为 -1。
输出 d(1),d(2),...,d(n)。
输入
10
4 5 7 6 7 5 4 4 6 4
输出
1 1 1 2 -1 1 1 3 1 1 
*/

/*

提示 1：从起点出发不好计算的话，试试从终点出发反着走。
反图怎么建？如果存在 v->w 的边，则建一条 w->v 的边

提示 2：BFS。
*/
#include<bits/stdc++.h>
using namespace std;
 
const int N = 200010, M = 2 * N;
int h[N], e[M], ne[M], idx;
int n, a[N], d[N];
 
void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    memset(d, -1, sizeof d);
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i++) {
        if (i - a[i] >= 1) add(i - a[i], i);
        if (i + a[i] <= n) add(i + a[i], i);   
    }
    queue<int> q;
    for (int k = 1; k <= n; k++)
        for (int i = h[k]; i != -1; i = ne[i]) {
            int j = e[i];
            if ((a[k] ^ a[j]) & 1) // a[j] 和 a[k] 的奇偶性不一样，那么d[j]一定是确定的，且为1，将j加入队列
                q.emplace(j), d[j] = 1;
        }
    while (q.size()){
        int t = q.front();
        q.pop();
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (d[j] == -1) // 和a[t]奇偶性不同的都被置成1了，还是-1的一定和d[t]奇偶性相同, t能在队列里那么d[t]一定是确定的
                d[j] = d[t] + 1, q.emplace(j);
        }
    }
    for (int i = 1; i <= n; i++) printf("%d ", d[i]);
    return 0;
}
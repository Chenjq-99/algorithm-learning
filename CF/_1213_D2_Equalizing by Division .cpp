/*
https://codeforces.com/problemset/problem/1213/D2

输入 n k (1≤k≤n≤2e5) 和长为 n 的数组 a(1≤a[i]≤2e5)。

每次操作你可以让一个 a[i] 变为 floor(a[i]/2)。
要想得到至少 k 个相同的数，最少需要多少次操作？
*/
/*
策略：
y[v]，表示通过有x[v]个数通过y[v]次操作得到x[v]个v的操作次数
为什么要排序？贪心，x[v]个数通过操作变成v，那么这些数越小，操作的次数越少
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n, k;
int a[N], y[N], x[N];

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    int res = 0x3f3f3f3f;
    sort(a, a + n);
    for (int i = 0; i < n; i++)
        for (int j = 0, v = a[i]; v; v /= 2, j++) {
            y[v] += j;
            if (++x[v] == k) res = min(res, y[v]);
        }
    printf("%d", res);
    return 0;
}

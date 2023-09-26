#include<iostream>
#include<cstring>
using namespace std;

/*
https://codeforces.com/contest/414/problem/B

输入 u n(1≤u,n≤2000)。
输出有多少个长为 n 的数组 a，满足：
1. 1≤a[1]≤a[2]≤...≤a[n]≤u。
2. a[i] 整除 a[i+1]（或者说 a[i] 是 a[i+1] 的因子）。
答案模 1e9+7。

*/
const int N = 2010, MOD = 1e9 + 7;

int f[N][N], n, k;

int dfs(int i, int x) {
    if (i == k) return 1;
    if (f[i][x] != -1) return f[i][x];
    int res = 0;
    for (int j = x; j <= n; j += x) {
        res = ((long long)res + dfs(i + 1, j)) % MOD;
    }
    return f[i][x] = res;
}
int main() {
    cin >> n >> k;
    memset(f, -1, sizeof f);
    cout << dfs(0, 1) << endl;
    return 0;
}
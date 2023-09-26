/*
https://codeforces.com/contest/1324/problem/E

输入 n(≤2000) h L R (0≤L≤R<h≤2000) 和长为 n 的数组 a(1≤a[i]<h)。

对于每个 a[i]，你可以把它减一，或者保持不变（换句话说，每个 a[i] 至多 -1 一次）。
定义前缀和 s[0]=a[0], s[i]=s[i-1]+a[i]。
如果 s[i]%h 落在闭区间 [L,R] 内，则分数加一。
最大化分数。

输入
7 24 21 23
16 17 14 20 20 11 22
输出 3
*/

/*
这道题的dp应该是两维的，1.在哪一位，2.之前的preSum是多少 因此定义dp[i][preSum]
preSum 最大是2000 * 2000 = 4000000
i 最大是200，那么数组就是8x10^9,这是不可以接受的
考虑到正难则反，我们可以不记录前缀和，由于原数组的前缀和是一定的，我们可以记录前i个元素，有j个做了-1，那么preSum = s[i] - j
j 的最大范围是2000，这样二维数组的规模就减小到了2000 * 2000 = 4 x 10^6
记忆化：dfs(i,j) =  max(dfs(i + 1, j), dfs(i + 1, j + 1)) + ((s[i] - j) % h >= l && (s[i] - j) % h <= r)
DP:f[i][j] = max(f[i - 1][j], f[i - 1][j - 1]) + ((s[i] - j) % h >= l && (s[i] - j) % h <= r)
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 2010;
int n, h, l, r, s[N];
int memo[N][N];
int f[N][N];

int main() {
    scanf("%d%d%d%d", &n, &h, &l, &r);
    for (int i = 1; i <= n; i++) {
        int a;
        scanf("%d", &a);
        s[i] = s[i - 1] + a;
    }
    // 记忆化搜索
    memset(memo, -1, sizeof memo);
    function<int(int, int)> dfs = [&](int i, int j) ->int {
        if (i == n) {
            if ((s[i] - j) % h >= l && (s[i] - j) % h <= r) return 1;
            return 0;
        }
        if (memo[i][j] != -1) return memo[i][j];
        int res = max(dfs(i + 1, j), dfs(i + 1, j + 1));
        if ((s[i] - j) % h >= l && (s[i] - j) % h <= r) res++;
        return memo[i][j] = res;
    };
    printf("%d", max(dfs(1, 0), dfs(1,1)));
    // DP
    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            f[i][j] = max(f[i - 1][j], f[i - 1][j - 1]);
            if ((s[i] - j) % h >= l && (s[i] - j) % h <= r) f[i][j]++;
            if (i == n) res = max(res, f[i][j]);
        }
    }
    printf("%d", res);
    return 0;
}
/*
https://codeforces.com/problemset/problem/1361/B

输入 t(≤1e5) 表示 t 组数据，每组数据输入 n(≤1e6) p(1≤p≤1e6) 和长为 n 的数组 k(0≤k[i]≤1e6)。所有数据的 n 之和不超过 1e6。

从这 n 个数中选出若干个数（可以为空）组成一组，剩余的数组成另一组。
每组计算 pow(p,k[i]) 之和。
输出这两个和的差值的最小值，对结果模 1e9+7。
输入
4
5 2
2 3 4 4 3
3 1
2 10 1000
4 5
0 1 1 100
1 8
89
输出
4
1
146981438
747093407
*/

/*
策略：
1. 将数组k安降序排列
2. 看成p进制, p^k[i] >= p^[k+1] + p^[k+1] + ..... p^k[i+j]
3. 在进制里一个较大的数一定能用一堆比较小的数将它完全消除，或尽量消除，例如 8 4 4 4 2 2 1 1 1 【8=4+4】 【4=2+2】 【2=1+1】 【1】
4，当一个较大的数被消掉了以后(res = 0),下一个数作为较大的数，重复上述步骤，继续向后消除
5. 就是 res1 = 0 ， 因为是取了 MOD(1e9 + 7) 之后的，所以这个 res1 有可能是MOD的倍数，那么要判断 res1 是否真正为 0 ， 只需要简单的再搞一个res2 % mod(1e9 + 3) ， 
   和 res1 % MOD 一样 ， 只要这两个res1 和 res2 同时为 0 ， 就表示res1为0，而不是 res1 是 MOD 的倍数 ， 就像一个人说了不算， 两个才有正确性
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 1000010, MOD = 1e9 + 7, mod = 1e9 + 3;

int t, n, a, k[N];

bool cmp(int a, int b) {
    return a > b;
}
int qmi(int a, int b, int p) {
    LL res = 0;
    while(b) {
        if (b & 1) res = res * a % p;
        a = (LL) a * a % p;
        b >>= 1;
    }
    return res % p;
}
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &a);
        for (int i = 0; i < n; i++) scanf("%d", &k[i]);
        sort(k, k + n, cmp);
        int res1 = 0, res2 = 0;
        for (int i = 0; i < n; i++) {
            if (!res1 && !res2) {
                res1 = qmi(a, k[i], MOD);
                res2 = qmi(a, a[k], mod);
            } else {
                res1 = ((res1 - qmi(a, k[i], MOD))% MOD + MOD) % MOD;
                res2 = ((res2 - qmi(a, k[i], mod))% mod + mod) % mod;
            }
        }
        printf("%d\n", res1);
    }
    return 0;
}

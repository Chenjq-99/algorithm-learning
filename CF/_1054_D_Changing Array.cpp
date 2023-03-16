/*
https://codeforces.com/problemset/problem/1054/D

输入正整数 n(≤2e5) k(≤30) 和长为 n 的数组 a(0≤a[i]≤pow(2,k)-1)。

设 mask = (1<<k)-1，每次操作你可以把任意 a[i] 修改为 a[i] XOR mask，你可以操作任意次（包括 0 次）。
修改后，最多有多少个 a 的非空连续子数组，其异或和不等于 0？
*/
/*
思路，
1.要想子数组异或和为0的个数最少就是让前缀和中相同的数对最少
2.在原数组a[i]^mask,等价于在前缀和数组s[i]^mask,s[i+1]^mask,因此每个s[i]可以独立调节
3.s[i]和s[i] ^ mask 可以相互转换，他们两个看成一类，然后等分成两堆，这样结果最小
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL c2(int n) {
    return ((long long)n * n - n) / 2;
}
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    map<int, int> cnt;  
    cnt[0] = 1;
    int t = 0, x = 0, mask = (1 << k) - 1;
    LL res = c2(n + 1);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        t ^= x;
        cnt[min(t, t ^ mask)]++;
    }
    for (auto &it : cnt) {
        int c = it.second;
        res -= c2(c / 2) + c2(c - c / 2);
    }
    printf("%lld\n", res);
    return 0;
} 
// https://codeforces.com/contest/1442/problem/A
#include<bits/stdc++.h>
using namespace std;

/*

输入 t(≤3e4) 表示 t 组数据，每组数据输入 n(≤3e4) 和长为 n 的数组 a(1≤a[i]≤1e6)。所有数据的 n 之和不超过 3e4。

每次操作，你可以把 a 的任意一个前缀或后缀的元素都减一。
你能否把所有 a[i] 都变成 0？输出 YES 或 NO。
输入
4
3
1 2 1
5
11 7 9 6 8
5
1 3 1 3 1
4
5 2 1 10
输出
YES
YES
NO
YES
*/

// 答案
/*

提示 1：区间加减，用差分数组 d 来思考。
定义 d[0] = a[0]，d[i] = a[i] - a[i-1]。

提示 2：
前缀减一，视作 d[0]-- 和 d[i]++。
后缀减一，视作 d[i]--（和 d[n]++，可以忽略）。
我们需要把 d[i] 都变成 0。

提示 3：
前缀操作用于修改 d[i]<0 的，但是操作次数之和不能超过 d[0]。
后缀操作用于修改 d[i]>0 的，无其他约束。

所以只需要判断「负数 d[i] 的绝对值之和」<= d[0]，满足就是 YES，否则为 NO。
*/
int main() {
    int t, n;
    cin >>t;
    while (t--) {
        cin >> n;
        int s, cur, prev;
        cin >> prev;
        s = prev;
        for (int i = 1; i < n; i++) {
            cin >> cur;
            if (cur < prev) s -= cur - prev;
            prev = cur;
        }
        if (s < 0) puts("NO");
        else puts("YES");
    }
    return 0;
}
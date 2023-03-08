/*
https://codeforces.com/problemset/problem/708/B

对于 01 字符串 s，定义 f(x,y) 表示子序列 [x,y] 在 s 中的出现次数。
输入 f(0,0), f(0,1), f(1,0) 和 f(1,1)，范围在 [0,1e9]。
请构造任意一个满足输入的非空字符串 s。
如果不存在，输出 Impossible。
注：子序列是从 s 中删除某些元素得到的。
*/
/*
https://codeforces.com/contest/708/submission/194669010

提示 1：根据 f(0,0) 可以求出 0 的个数 c0，因为 f(0,0) = C(c0,2)；同理可求出 1 的个数 c1。

提示 2：f(0,1) + f(1,0) = c0 * c1
*/
#include<bits/stdc++.h>
using namespace std;
 
int main() {
    int cnt_00, cnt_01, cnt_10, cnt_11;
    cin >> cnt_00 >> cnt_01 >> cnt_10 >> cnt_11;
    int c0 = sqrt(cnt_00 << 1) + 1, c1 = sqrt(cnt_11 << 1) + 1;
    (c0 < c1 ? c0 : c1) -= (!cnt_01 && !cnt_10);
    if (c0 * (c0 - 1) != cnt_00 + cnt_00 || c1 * (c1 - 1) != cnt_11 + cnt_11  || c0 * c1 != cnt_01 + cnt_10) {
        puts("Impossible");
    }
    else {
        if (!c0) for(int i = 0; i < c1; i++) putchar('1');
        else {
            while (cnt_10 >= c0) putchar('1'), cnt_10 -= c0;
            for (int i = 0; i < c0; i++) {
                if (cnt_10 == c0 - i) putchar('1');
                putchar('0');
            } 
            while (cnt_01 >= c0) putchar('1'), cnt_01 -= c0;
        }
    }
    return 0;
}
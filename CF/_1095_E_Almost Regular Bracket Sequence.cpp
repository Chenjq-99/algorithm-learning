/*
https://codeforces.com/problemset/problem/1095/E

输入 n(≤1e6) 和长为 n 的括号字符串 s。

你必须执行如下操作恰好一次：
选择一个下标 i，如果 s[i] 是 ')'，则修改为 '('，反之亦然。

有多少个不同的 i，可以使 s 是一个合法的括号字符串？
输入
6
(((())
输出 3

输入
8
)))(((((
输出 0
*/

/*

记 c 为 s 的平衡度，遇到 '(' 就 +1，遇到 ')' 就 -1。

中途 c 不能小于 -2。最后 abs(c) 必须为 2。

分类讨论：
如果 c 为 -2，那么要改 ')'，且只能修改从开头到第一次 c=-1 这一段的 )。
如果 c 为 2，那么要改 '('，那么 c 在任何时候都不能小于 0。
倒着遍历 s，统计 c > 1 时的 '('，因为一旦 c<=1 了，改成 ')' 肯定不能得到合法括号字符串了。
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 1000010;
int n;
char s[N];

int main() {
    scanf("%d%s", &n, s);
    int c = 0, res = 0, has_ans = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') c += 1;
        if (s[i] == ')') c -= 1;
        if (c < -2) {
            has_ans = 0;
            break;
        }
    }
    if (has_ans && abs(c) == 2) {
        if (c == -2) 
            for (int i = 0, cnt = 0, t = 0; i < n; i++) {
                if (s[i] == '(') t += 1;
                if (s[i] == ')') t -= 1, cnt += 1;
                if (t == -1) {
                    res += cnt;
                    break;
                }
            }
        if (c == 2) { 
            for (int i = 0, cnt = 0, t = 0; i < n; i++) {
                if (s[i] == '(') t += 1;
                if (s[i] == ')') t -= 1;
                if (t < 0) {
                    has_ans = 0;
                    break;
                }
            }
            if (has_ans)
                for (int i = n - 1, cnt = 0, t = 0; i; i--) {
                    if (s[i] == '(') t += 1, cnt += 1;
                    if (s[i] == ')') t -= 1;
                    if (t == 1) {
                        res += cnt;
                        break;
                    }
                }
        }
    }
    printf("%d", res);
    return 0;
}
/*
https://codeforces.com/problemset/problem/5/C

输入括号字符串 s，长度不超过 1e6。

输出 s 的最长合法括号子串的长度和数量。
如果不存在，输出 0 1。
*/
/*
使用栈做括号的匹配
开一个bool数组f，将成功匹配的位置记为1，
统计连续1的个数，注意这里是<= n利用第f[n] == 0,来做最终的检查
*/
#include<iostream>
#include<cstring>
using namespace std;

const int N = 1000010;

char s[N];
bool f[N];
int stack[N], top;

int main() {
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') stack[++top] = i;
        else if (top) f[i] = 1, f[stack[top]] = 1, top--; 
    }
    int res = 0, tot = 0;
    for (int i = 0, cnt = 0; i < n; i++) {
        if (f[i]) cnt++;
        else res = max(res, cnt), cnt = 0;
    }
    for (int i = 0, cnt = 0; i <= n; i++) {
        if (f[i]) cnt++;
        else {
            if (cnt == res) tot++, cnt = 0;
        }
    }
    if(res) printf("%d %d", res, tot);
    else puts("0 1\n");
    return 0;
}
#include<iostream>
using namespace std;
const int N = 1e5 + 10, M = 1e6 + 10;

char s[M], p[N];

int nxt[N]; //next 数组

int m, n;

int main () {
    // 字符串的起始下标从1开始, 方便处理边界
    cin >> n >> p + 1 >> m >> s + 1;
    
    // 求解next数组
    for (int i = 2, j = 0; i <= n; i++) {
        while (j && p[i] != p[j + 1]) j = nxt[j];
        if (p[i] == p[j + 1]) j++;
        nxt[i] = j;
    }
    // KMP匹配过程
    for (int i = 1, j= 0; i <= m; i++) {
        while (j && s[i] != p[j + 1]) j = nxt[j];
        if (s[i] == p[j + 1]) j++;
        if (j == n) {
            // 匹配成功
            printf("%d", i - n + 1);
            j = nxt[j];
        }
    }
    return 0;
}
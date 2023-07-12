
// kmp
int nxt[100010], f[100010]; // nxt[i]表示p[1~i]的最长公共前后缀长度，f[i]表示s[1~i]的最长公共前后缀长度
int m, n; // m为p的长度，n为s的长度
char s[100010], p[100010]; // s为主串，p为模式串

void kmp() {
    //字符串下标从1开始
    for (int i = 2, j = 0; i <= m; i++) {
        while (j && p[i] != p[j + 1]) j = nxt[j];
        if (p[i] == p[j + 1]) j++;
        nxt[i] = j;
    }
    for (int i = 1, j= 0; i <= n; i++) {
        while (j == m || j && s[i] != p[j + 1]) j = nxt[j];
        if (s[i] == p[j + 1]) j++;
            f[i] = j;
    }
}

void kmp() {
    // p要开两倍大小
    p[m + 1] = '#'; // 用于区分s和p
    for (int i = m + 2, j = 1; i <= m + n + 1; i++, j++) 
        p[i] = s[j];
    for (int i = 2, j = 0; i <= m + n + 1; i++) {
        while (j && p[i] != p[j + 1]) j = nxt[j];
        if (p[i] == p[j + 1]) j++;
        nxt[i] = j;
    }
    // 从第m + 2下标开始就是s所对应的匹配长度
}
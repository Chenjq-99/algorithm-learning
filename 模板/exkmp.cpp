
// exkmp
// s[1..n] 为模式串，t[1..m] 为主串
// z[i] 表示 s[i..n] 与 t 的最长公共前缀

int z[100010], n, m;
char s[100010], t[100010];

void exkmp() {
    int L = 1, R = 1;
    z[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (i <= R) 
            z[i] = min(R - i + 1, z[i - L + 1]);
        while (i + z[i] <= n && s[i + z[i]] == t[1 + z[i]]) 
            z[i]++;
        if (i + z[i] - 1 > R) 
            L = i, R = i + z[i] - 1;
    }
}
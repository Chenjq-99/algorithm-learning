#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, p[2 * N];
char s[N], t[2 * N];

void manacher() {
    n = strlen(s + 1);
    int m = 0;
    t[++m] = '$';
    for (int i = 1; i <= n; i++) 
        t[++m] = s[i], t[++m] = '$';
    int M = 0, R = 0;
    for (int i = 0; i < m; i++) {
        if (i > R) 
            p[i] = 1;
        else 
            p[i] = min(p[2 * M - i], R - i);
        while (i - p[i] > 0 && i + p[i] <= m && t[i - p[i]] == t[i + p[i]]) 
            p[i]++;
        if (i + p[i] - 1 > R)
            M = i, R = i + p[i] - 1;
        int ans = 0;
        for (int i = 0; i < m; i++) 
            ans = max(ans, p[i] - 1);
        printf("%d\n", ans);
    }
}
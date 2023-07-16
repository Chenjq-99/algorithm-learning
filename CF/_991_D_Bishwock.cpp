#include<bits/stdc++.h>

using namespace std;

int n, a[110], f[110][4];
char s1[110], s2[110];

int main() {

    scanf("%s%s", s1 + 1, s2 + 1);

    n = strlen(s1 + 1);

    for (int i = 1; i <= n; i++) {
        if (s1[i] == 'X') a[i] += 1;
        if (s2[i] == 'X') a[i] += 2;
        // cout << a[i] << endl;
    }
    memset(f, -0x3f, sizeof f);
    f[1][a[1]] = 0;
    for (int i = 2; i <= n; i++) {
        // 不放积木
        f[i][a[i]] = *max_element(f[i - 1], f[i - 1] + 4);
       // 放积木
       if (!(a[i] & 1)) f[i][1 | a[i]] = f[i - 1][0] + 1;
       if (!(a[i] & 2)) f[i][2 | a[i]] = f[i - 1][0] + 1;
       if (!a[i]) {
            f[i][3] = *max_element(f[i - 1], f[i - 1] + 3) + 1;
       } 
    }
    printf("%d\n", *max_element(f[n], f[n] + 4));

    return 0;
}
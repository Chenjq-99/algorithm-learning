#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef unsigned long long ULL;

const int N = 10010, M = 1510, P = 131;

int n, ans = 1;

char str[M];

ULL h[N];

ULL get_hash (char str[]) {
    ULL res = 0;
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        res = res * (ULL)P + (ULL)str[i];
    }
    return res;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", str);
        h[i] = get_hash(str);
    }
    sort(h + 1, h + n + 1);
    for (int i = 1; i < n; i++) {
        if (h[i] != h[i + 1]) ans++;
    }
    printf("%d", ans);
    return 0;
}


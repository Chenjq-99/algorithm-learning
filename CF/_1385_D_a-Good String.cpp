#include<bits/stdc++.h>
using namespace std;

char s[200005];

int solve(int l, int r, int x) {
    if (l == r)
        return s[l] != x;
    int m = (l + r) >> 1;
    int y1 = 0, y2 = 0;
    for (int i = l; i <= m; i++)
        if(s[i] != x)
            y1++;
    for (int i = m + 1; i <= r; i++) 
        if (s[i] != x)
            y2++;
    return min(y1 + solve(m + 1, r, x + 1), y2 + solve(l, m, x + 1));

}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d%s", &n, s + 1);
        printf("%d\n", solve(1, n, 'a'));
    }
    return 0;
}
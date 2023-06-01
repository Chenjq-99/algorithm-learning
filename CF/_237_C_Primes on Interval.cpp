#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int a, b, k, cnt, s[N];

bool st[N];

int main() {
    scanf("%d%d%d", &a, &b, &k);
    memset(st, false, sizeof st);
    for (int i = 2; i <= b; i++) {
        if (!st[i]) {
            s[i] = ++cnt;
            for (int j = i; j <= b; j += i) {
                st[j] = true;
            }
        } else {
            s[i] = cnt;
        }
    }
    int t = b - a + 1;
    if (k <= t) {
        int l = k, r = t;
        while (l < r) {
            int mid = (l + r) >> 1;
            bool success = true;
            for (int x = a; x <= b - mid + 1; x++) {
                if (s[x + mid - 1] - s[x - 1] < k) {
                    success = false;
                    break;
                }
            }
            if (success) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        printf("%d", l);
    } else {
        printf("%d", -1);
    }
    return 0;
}
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

const int N = 5005;

long long s[N];
int n;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int a;
        scanf("%d", &a);
        s[i] = s[i - 1] + a;
    }
    long long mx = -1e9;
    int ans[3] = {1, 1, 1};
    for (int i = 1; i <= n; i++) {
        int j = i;
        for (int k = i; k <= n; k++) {
            if (s[k] < s[j]) {
                j = k;
            } else {
                if (s[i] + s[k] - s[j - 1] > mx) {
                    mx = s[i] + s[k] - s[j - 1];
                    ans[0] = i, ans[1] = j, ans[2] = k;
                }
            }
        }
    }
    printf("%d %d %d\n", ans[0], ans[1], ans[2]);
    return 0;
}
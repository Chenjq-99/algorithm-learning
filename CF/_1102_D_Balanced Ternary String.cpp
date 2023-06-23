/*
https://codeforces.com/problemset/problem/1102/D

输入 n(3≤n≤3e5 且 n=3k) 和长为 n 的字符串 s，只包含 012。
你需要修改 s 中的字符，使得 012 的数量都等于 n/3。
修改次数应当尽量少。
输出修改后的字典序最小的字符串。
*/

/*
https://codeforces.com/contest/1102/submission/207636737

为了最小化修改次数，只需要修改出现次数 > n/3 的。
从左往右，大的改成小的，例如 2->0
从右往左，小的改成大的，例如 1->2
*/
#include<bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int n, cnt[3];

char s[N];

int main() {
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; i++) {
        cnt[s[i] - '0']++;
    }
    for (int i = 0; i < n; i++) {
        int t = s[i] - '0';
        if (t > 0 && cnt[t] > n / 3) {
            if (cnt[0] < n / 3) {
                cnt[0]++;
                cnt[t]--;
                s[i] = '0';
            } else if (cnt[1] < n / 3) {
                cnt[1]++;
                cnt[t]--;
                s[i] = '1';
            }
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        int t = s[i] - '0';
        if (cnt[t] > n / 3) {
            if (cnt[2] < n / 3) {
                cnt[2]++;
                cnt[t]--;
                s[i] = '2';
            } else if (cnt[1] < n / 3) {
                cnt[1]++;
                cnt[t]--;
                s[i] = '1';
            }
        }
    }
    printf("%s\n", s);
    return 0;
}
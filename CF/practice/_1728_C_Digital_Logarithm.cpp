#include<bits/stdc++.h>


using namespace std;

const int N = 200010;

int n;
int a[N], b[N];

int getLength(int x) {
    int cnt = 0;
    while (x) {
        cnt++;
        x /= 10;
    }
    return cnt;
}

void solve() {
    int res = 0;
    priority_queue<int, vector<int>, less<int>> A, B;
    scanf("%d", &n);
    int x, y;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        A.push(x);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        B.push(x);
    }
    while (!A.empty()) {
        x = A.top(), y = B.top();
        if (x > y) {
            A.pop();
            A.push(getLength(x));
            res++;
        } else if (x < y) {
            B.pop();
            B.push(getLength(y));
            res++;
        } else {
            A.pop();
            B.pop();
        }
    }
    printf("%d\n", res);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) solve();
    return 0;
}
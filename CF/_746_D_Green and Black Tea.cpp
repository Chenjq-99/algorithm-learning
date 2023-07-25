#include<bits/stdc++.h>
using namespace std;

const int N = 100010;

int n, k, a, b;

int main() {
    cin >> n >> k >> a >> b;
    int x = min(a, b), y = max(a, b);
    char c = x == a ? 'G' : 'B', d = x == a ? 'B' : 'G';
    if (1ll * (x + 1) * k >= y) {
        while (x) {
            int j = min(k, y);
            int t = min(x - (y - j + k - 1) / k + 1, min(x, k));
            x -= t, y -= j;
            for (int i = 0; i < j; i++) cout << d;
            for (int i = 0; i < t; i++) cout << c;
        } 
        for (int i = 0; i < y; i++) cout << d;
        cout << endl;
    } else {
        puts("NO");
    }
    return 0;
}
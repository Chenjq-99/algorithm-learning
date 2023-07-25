#include<bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, a[2][N];
long long f[3][N];

int main() {
    cin >> n;
    for (int i = 0; i < 2; i++)
        for (int j = 1; j < n; j++)
            cin >> a[i][j];
    for (int i = 1; i < n; i++) {
        f[0][i] = max(f[1][i - 1], f[2][i - 1]) + a[0][i];
        f[1][i] = max(f[0][i - 1], f[2][i - 1]) + a[1][i];
        f[2][i] = max(f[0][i - 1], max(f[1][i - 1], f[2][i - 1]));
    }
    cout << max(f[0][n], max(f[1][n], f[2][n])) << endl;
    return 0;
}
#include<iostream>
#include<cstring>
using namespace std;

/*
https://codeforces.com/contest/414/problem/B

���� u n(1��u,n��2000)��
����ж��ٸ���Ϊ n ������ a�����㣺
1. 1��a[1]��a[2]��...��a[n]��u��
2. a[i] ���� a[i+1]������˵ a[i] �� a[i+1] �����ӣ���
��ģ 1e9+7��

*/
const int N = 2010, MOD = 1e9 + 7;

int f[N][N], n, k;

int dfs(int i, int x) {
    if (i == k) return 1;
    if (f[i][x] != -1) return f[i][x];
    int res = 0;
    for (int j = x; j <= n; j += x) {
        res = ((long long)res + dfs(i + 1, j)) % MOD;
    }
    return f[i][x] = res;
}
int main() {
    cin >> n >> k;
    memset(f, -1, sizeof f);
    cout << dfs(0, 1) << endl;
    return 0;
}
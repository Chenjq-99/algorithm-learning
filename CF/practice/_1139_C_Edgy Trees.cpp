// https://codeforces.com/problemset/problem/1139/C

/*

���� n(2��n��1e5) k(2��k��100) ��һ���������� n-1 ���ߣ��ڵ��Ŵ� 1 ��ʼ����ÿ���߰��� 3 ���� x y c��
��ʾ��һ����ɫΪ c �ı����� x �� y������ c ���� 0 �� 1��

���ڳ�Ϊ k �ڵ����� a�������·����˳�򾭹��ڵ� a1 -> a2 -> ... -> ak��
�������г�Ϊ k �Ľڵ����� a������ n^k ������ͳ�����پ���һ�� c=1 �ıߵ����� a �ĸ�����
*/

/*
�����򷴣�ͳ��ֻ���� c=0 ����������
�൱�ڼ���ÿ�� c=0 ��ɵ���ͨ��Ĵ�С sz����Ӧ��ֻ���� c=0 ������Ϊ sz^k��
��Ϊ n^k - ��sz^k���ÿ����ݼ��㡣
*/
#include<bits/stdc++.h>

using namespace std;

const int N = 100010, MOD = 1e9 + 7;
int p[N], h[N];
int n, k;

int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
}

int qmi(int a, int b, int p) {
    int res = 1;
    while (b) {
        if (b & 1) res = (long long)res * a % p;
        b >>= 1;
        a = (long long)a * a % p;
    }
    return res;
}
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        if (!c) {
            p[find(u)] = find(v);
        }
    }
    for (int i = 1; i <= n; i++) {
        h[find(i)]++;
    }
    int ans = qmi(n, k, MOD);
    for (int i = 1; i <= n; i++) {
        ans = (ans - qmi(h[i], k, MOD) + MOD) % MOD;
    }
    printf("%d\n", ans);
    return 0;
}
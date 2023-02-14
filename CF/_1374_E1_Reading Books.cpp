/*
https://codeforces.com/contest/1374/problem/E1

���� n k (1��k��n��2e5)����ʾ�� n ���飬Ȼ������ n �У�ÿ������ t(1��t��1e4) a b������ a=0/1 ��ʾ A ��ϲ��/ϲ���Ȿ�飬b=0/1 ��ʾ B ��ϲ��/ϲ���Ȿ�顣

����Ҫѡ��һЩ�飬ʹ������������ k ���� A ϲ���ģ������� k ���� B ϲ���ġ�
����޷�������� -1�����������ѡ��� t ֮�͵���Сֵ��

����
8 4
7 1 1
2 1 1
4 0 1
8 1 1
1 0 1
1 1 1
1 0 1
3 0 0
��� 18
*/

/*

��ʾ��ö���� x �����������˶�ϲ���ġ�
ʣ�µľ���ѡ k-x ��ֻ�� A ϲ���ģ�k-x ��ֻ�� B ϲ���ġ�
�������ǰ׺���ټ��㡣
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 200010;
int n, k, t, a, b;
int a1[N], a2[N], a3[N], idx1, idx2, idx3;
int s1[N], s2[N], s3[N];

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &t, &a, &b);
        if (a == 1 && b == 1) a3[idx3++] = t;
        if (a == 0 && b == 1) a2[idx2++] = t;
        if (a == 1 && b == 0) a1[idx1++] = t;
    }
    if (idx1 + idx3 < k || idx2 + idx3 < k) {
        printf("%d",-1);
        return 0;
    }
    sort(a1,a1 + idx1), sort(a2, a2 + idx2), sort(a3, a3 + idx3);
    for (int i = 1; i <= idx1; i++) s1[i] = s1[i - 1] + a1[i - 1];
    for (int i = 1; i <= idx2; i++) s2[i] = s2[i - 1] + a2[i - 1];
    for (int i = 1; i <= idx3; i++) s3[i] = s3[i - 1] + a3[i - 1];
    int m = min(k, idx3), res = 2e9;
    for (int i = 0; i <= m; i++) {
        if (idx1 < k - i || idx2 < k - i) continue;
        res = min(res, s3[i] + s1[k - i] + s2[k - i]);
    }
    printf("%d", res);
    return 0;
}
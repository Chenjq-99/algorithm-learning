/*
https://codeforces.com/problemset/problem/1213/D2

���� n k (1��k��n��2e5) �ͳ�Ϊ n ������ a(1��a[i]��2e5)��

ÿ�β����������һ�� a[i] ��Ϊ floor(a[i]/2)��
Ҫ��õ����� k ����ͬ������������Ҫ���ٴβ�����
*/
/*
���ԣ�
y[v]����ʾͨ����x[v]����ͨ��y[v]�β����õ�x[v]��v�Ĳ�������
ΪʲôҪ����̰�ģ�x[v]����ͨ���������v����ô��Щ��ԽС�������Ĵ���Խ��
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n, k;
int a[N], y[N], x[N];

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    int res = 0x3f3f3f3f;
    sort(a, a + n);
    for (int i = 0; i < n; i++)
        for (int j = 0, v = a[i]; v; v /= 2, j++) {
            y[v] += j;
            if (++x[v] == k) res = min(res, y[v]);
        }
    printf("%d", res);
    return 0;
}

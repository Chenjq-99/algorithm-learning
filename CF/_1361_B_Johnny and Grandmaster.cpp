/*
https://codeforces.com/problemset/problem/1361/B

���� t(��1e5) ��ʾ t �����ݣ�ÿ���������� n(��1e6) p(1��p��1e6) �ͳ�Ϊ n ������ k(0��k[i]��1e6)���������ݵ� n ֮�Ͳ����� 1e6��

���� n ������ѡ�����ɸ���������Ϊ�գ����һ�飬ʣ����������һ�顣
ÿ����� pow(p,k[i]) ֮�͡�
����������͵Ĳ�ֵ����Сֵ���Խ��ģ 1e9+7��
����
4
5 2
2 3 4 4 3
3 1
2 10 1000
4 5
0 1 1 100
1 8
89
���
4
1
146981438
747093407
*/

/*
���ԣ�
1. ������k����������
2. ����p����, p^k[i] >= p^[k+1] + p^[k+1] + ..... p^k[i+j]
3. �ڽ�����һ���ϴ����һ������һ�ѱȽ�С����������ȫ�������������������� 8 4 4 4 2 2 1 1 1 ��8=4+4�� ��4=2+2�� ��2=1+1�� ��1��
4����һ���ϴ�������������Ժ�(res = 0),��һ������Ϊ�ϴ�������ظ��������裬�����������
5. ���� res1 = 0 �� ��Ϊ��ȡ�� MOD(1e9 + 7) ֮��ģ�������� res1 �п�����MOD�ı�������ôҪ�ж� res1 �Ƿ�����Ϊ 0 �� ֻ��Ҫ�򵥵��ٸ�һ��res2 % mod(1e9 + 3) �� 
   �� res1 % MOD һ�� �� ֻҪ������res1 �� res2 ͬʱΪ 0 �� �ͱ�ʾres1Ϊ0�������� res1 �� MOD �ı��� �� ����һ����˵�˲��㣬 ����������ȷ��
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 1000010, MOD = 1e9 + 7, mod = 1e9 + 3;

int t, n, a, k[N];

bool cmp(int a, int b) {
    return a > b;
}
int qmi(int a, int b, int p) {
    LL res = 0;
    while(b) {
        if (b & 1) res = res * a % p;
        a = (LL) a * a % p;
        b >>= 1;
    }
    return res % p;
}
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &a);
        for (int i = 0; i < n; i++) scanf("%d", &k[i]);
        sort(k, k + n, cmp);
        int res1 = 0, res2 = 0;
        for (int i = 0; i < n; i++) {
            if (!res1 && !res2) {
                res1 = qmi(a, k[i], MOD);
                res2 = qmi(a, a[k], mod);
            } else {
                res1 = ((res1 - qmi(a, k[i], MOD))% MOD + MOD) % MOD;
                res2 = ((res2 - qmi(a, k[i], mod))% mod + mod) % mod;
            }
        }
        printf("%d\n", res1);
    }
    return 0;
}

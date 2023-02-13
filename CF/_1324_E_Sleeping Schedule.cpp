/*
https://codeforces.com/contest/1324/problem/E

���� n(��2000) h L R (0��L��R<h��2000) �ͳ�Ϊ n ������ a(1��a[i]<h)��

����ÿ�� a[i]������԰�����һ�����߱��ֲ��䣨���仰˵��ÿ�� a[i] ���� -1 һ�Σ���
����ǰ׺�� s[0]=a[0], s[i]=s[i-1]+a[i]��
��� s[i]%h ���ڱ����� [L,R] �ڣ��������һ��
��󻯷�����

����
7 24 21 23
16 17 14 20 20 11 22
��� 3
*/

/*
������dpӦ������ά�ģ�1.����һλ��2.֮ǰ��preSum�Ƕ��� ��˶���dp[i][preSum]
preSum �����2000 * 2000 = 4000000
i �����200����ô�������8x10^9,���ǲ����Խ��ܵ�
���ǵ������򷴣����ǿ��Բ���¼ǰ׺�ͣ�����ԭ�����ǰ׺����һ���ģ����ǿ��Լ�¼ǰi��Ԫ�أ���j������-1����ôpreSum = s[i] - j
j �����Χ��2000��������ά����Ĺ�ģ�ͼ�С����2000 * 2000 = 4 x 10^6
���仯��dfs(i,j) =  max(dfs(i + 1, j), dfs(i + 1, j + 1)) + ((s[i] - j) % h >= l && (s[i] - j) % h <= r)
DP:f[i][j] = max(f[i - 1][j], f[i - 1][j - 1]) + ((s[i] - j) % h >= l && (s[i] - j) % h <= r)
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 2010;
int n, h, l, r, s[N];
int memo[N][N];
int f[N][N];

int main() {
    scanf("%d%d%d%d", &n, &h, &l, &r);
    for (int i = 1; i <= n; i++) {
        int a;
        scanf("%d", &a);
        s[i] = s[i - 1] + a;
    }
    // ���仯����
    memset(memo, -1, sizeof memo);
    function<int(int, int)> dfs = [&](int i, int j) ->int {
        if (i == n) {
            if ((s[i] - j) % h >= l && (s[i] - j) % h <= r) return 1;
            return 0;
        }
        if (memo[i][j] != -1) return memo[i][j];
        int res = max(dfs(i + 1, j), dfs(i + 1, j + 1));
        if ((s[i] - j) % h >= l && (s[i] - j) % h <= r) res++;
        return memo[i][j] = res;
    };
    printf("%d", max(dfs(1, 0), dfs(1,1)));
    // DP
    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            f[i][j] = max(f[i - 1][j], f[i - 1][j - 1]);
            if ((s[i] - j) % h >= l && (s[i] - j) % h <= r) f[i][j]++;
            if (i == n) res = max(res, f[i][j]);
        }
    }
    printf("%d", res);
    return 0;
}
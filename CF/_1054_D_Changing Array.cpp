/*
https://codeforces.com/problemset/problem/1054/D

���������� n(��2e5) k(��30) �ͳ�Ϊ n ������ a(0��a[i]��pow(2,k)-1)��

�� mask = (1<<k)-1��ÿ�β�������԰����� a[i] �޸�Ϊ a[i] XOR mask������Բ�������Σ����� 0 �Σ���
�޸ĺ�����ж��ٸ� a �ķǿ����������飬�����Ͳ����� 0��
*/
/*
˼·��
1.Ҫ������������Ϊ0�ĸ������پ�����ǰ׺������ͬ����������
2.��ԭ����a[i]^mask,�ȼ�����ǰ׺������s[i]^mask,s[i+1]^mask,���ÿ��s[i]���Զ�������
3.s[i]��s[i] ^ mask �����໥ת����������������һ�࣬Ȼ��ȷֳ����ѣ����������С
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL c2(int n) {
    return ((long long)n * n - n) / 2;
}
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    map<int, int> cnt;  
    cnt[0] = 1;
    int t = 0, x = 0, mask = (1 << k) - 1;
    LL res = c2(n + 1);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        t ^= x;
        cnt[min(t, t ^ mask)]++;
    }
    for (auto &it : cnt) {
        int c = it.second;
        res -= c2(c / 2) + c2(c - c / 2);
    }
    printf("%lld\n", res);
    return 0;
} 
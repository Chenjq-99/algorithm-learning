// https://codeforces.com/contest/1442/problem/A
#include<bits/stdc++.h>
using namespace std;

/*

���� t(��3e4) ��ʾ t �����ݣ�ÿ���������� n(��3e4) �ͳ�Ϊ n ������ a(1��a[i]��1e6)���������ݵ� n ֮�Ͳ����� 3e4��

ÿ�β���������԰� a ������һ��ǰ׺���׺��Ԫ�ض���һ��
���ܷ������ a[i] ����� 0����� YES �� NO��
����
4
3
1 2 1
5
11 7 9 6 8
5
1 3 1 3 1
4
5 2 1 10
���
YES
YES
NO
YES
*/

// ��
/*

��ʾ 1������Ӽ����ò������ d ��˼����
���� d[0] = a[0]��d[i] = a[i] - a[i-1]��

��ʾ 2��
ǰ׺��һ������ d[0]-- �� d[i]++��
��׺��һ������ d[i]--���� d[n]++�����Ժ��ԣ���
������Ҫ�� d[i] ����� 0��

��ʾ 3��
ǰ׺���������޸� d[i]<0 �ģ����ǲ�������֮�Ͳ��ܳ��� d[0]��
��׺���������޸� d[i]>0 �ģ�������Լ����

����ֻ��Ҫ�жϡ����� d[i] �ľ���ֵ֮�͡�<= d[0]��������� YES������Ϊ NO��
*/
int main() {
    int t, n;
    cin >>t;
    while (t--) {
        cin >> n;
        int s, cur, prev;
        cin >> prev;
        s = prev;
        for (int i = 1; i < n; i++) {
            cin >> cur;
            if (cur < prev) s -= cur - prev;
            prev = cur;
        }
        if (s < 0) puts("NO");
        else puts("YES");
    }
    return 0;
}
/*
https://codeforces.com/problemset/problem/1102/D

���� n(3��n��3e5 �� n=3k) �ͳ�Ϊ n ���ַ��� s��ֻ���� 012��
����Ҫ�޸� s �е��ַ���ʹ�� 012 ������������ n/3��
�޸Ĵ���Ӧ�������١�
����޸ĺ���ֵ�����С���ַ�����
*/

/*
https://codeforces.com/contest/1102/submission/207636737

Ϊ����С���޸Ĵ�����ֻ��Ҫ�޸ĳ��ִ��� > n/3 �ġ�
�������ң���ĸĳ�С�ģ����� 2->0
��������С�ĸĳɴ�ģ����� 1->2
*/
#include<bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int n, cnt[3];

char s[N];

int main() {
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; i++) {
        cnt[s[i] - '0']++;
    }
    for (int i = 0; i < n; i++) {
        int t = s[i] - '0';
        if (t > 0 && cnt[t] > n / 3) {
            if (cnt[0] < n / 3) {
                cnt[0]++;
                cnt[t]--;
                s[i] = '0';
            } else if (cnt[1] < n / 3) {
                cnt[1]++;
                cnt[t]--;
                s[i] = '1';
            }
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        int t = s[i] - '0';
        if (cnt[t] > n / 3) {
            if (cnt[2] < n / 3) {
                cnt[2]++;
                cnt[t]--;
                s[i] = '2';
            } else if (cnt[1] < n / 3) {
                cnt[1]++;
                cnt[t]--;
                s[i] = '1';
            }
        }
    }
    printf("%s\n", s);
    return 0;
}
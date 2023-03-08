/*
https://codeforces.com/problemset/problem/708/B

���� 01 �ַ��� s������ f(x,y) ��ʾ������ [x,y] �� s �еĳ��ִ�����
���� f(0,0), f(0,1), f(1,0) �� f(1,1)����Χ�� [0,1e9]��
�빹������һ����������ķǿ��ַ��� s��
��������ڣ���� Impossible��
ע���������Ǵ� s ��ɾ��ĳЩԪ�صõ��ġ�
*/
/*
https://codeforces.com/contest/708/submission/194669010

��ʾ 1������ f(0,0) ������� 0 �ĸ��� c0����Ϊ f(0,0) = C(c0,2)��ͬ������ 1 �ĸ��� c1��

��ʾ 2��f(0,1) + f(1,0) = c0 * c1
*/
#include<bits/stdc++.h>
using namespace std;
 
int main() {
    int cnt_00, cnt_01, cnt_10, cnt_11;
    cin >> cnt_00 >> cnt_01 >> cnt_10 >> cnt_11;
    int c0 = sqrt(cnt_00 << 1) + 1, c1 = sqrt(cnt_11 << 1) + 1;
    (c0 < c1 ? c0 : c1) -= (!cnt_01 && !cnt_10);
    if (c0 * (c0 - 1) != cnt_00 + cnt_00 || c1 * (c1 - 1) != cnt_11 + cnt_11  || c0 * c1 != cnt_01 + cnt_10) {
        puts("Impossible");
    }
    else {
        if (!c0) for(int i = 0; i < c1; i++) putchar('1');
        else {
            while (cnt_10 >= c0) putchar('1'), cnt_10 -= c0;
            for (int i = 0; i < c0; i++) {
                if (cnt_10 == c0 - i) putchar('1');
                putchar('0');
            } 
            while (cnt_01 >= c0) putchar('1'), cnt_01 -= c0;
        }
    }
    return 0;
}
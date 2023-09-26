/*
https://codeforces.com/problemset/problem/1095/E

���� n(��1e6) �ͳ�Ϊ n �������ַ��� s��

�����ִ�����²���ǡ��һ�Σ�
ѡ��һ���±� i����� s[i] �� ')'�����޸�Ϊ '('����֮��Ȼ��

�ж��ٸ���ͬ�� i������ʹ s ��һ���Ϸ��������ַ�����
����
6
(((())
��� 3

����
8
)))(((((
��� 0
*/

/*

�� c Ϊ s ��ƽ��ȣ����� '(' �� +1������ ')' �� -1��

��; c ����С�� -2����� abs(c) ����Ϊ 2��

�������ۣ�
��� c Ϊ -2����ôҪ�� ')'����ֻ���޸Ĵӿ�ͷ����һ�� c=-1 ��һ�ε� )��
��� c Ϊ 2����ôҪ�� '('����ô c ���κ�ʱ�򶼲���С�� 0��
���ű��� s��ͳ�� c > 1 ʱ�� '('����Ϊһ�� c<=1 �ˣ��ĳ� ')' �϶����ܵõ��Ϸ������ַ����ˡ�
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 1000010;
int n;
char s[N];

int main() {
    scanf("%d%s", &n, s);
    int c = 0, res = 0, has_ans = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') c += 1;
        if (s[i] == ')') c -= 1;
        if (c < -2) {
            has_ans = 0;
            break;
        }
    }
    if (has_ans && abs(c) == 2) {
        if (c == -2) 
            for (int i = 0, cnt = 0, t = 0; i < n; i++) {
                if (s[i] == '(') t += 1;
                if (s[i] == ')') t -= 1, cnt += 1;
                if (t == -1) {
                    res += cnt;
                    break;
                }
            }
        if (c == 2) { 
            for (int i = 0, cnt = 0, t = 0; i < n; i++) {
                if (s[i] == '(') t += 1;
                if (s[i] == ')') t -= 1;
                if (t < 0) {
                    has_ans = 0;
                    break;
                }
            }
            if (has_ans)
                for (int i = n - 1, cnt = 0, t = 0; i; i--) {
                    if (s[i] == '(') t += 1, cnt += 1;
                    if (s[i] == ')') t -= 1;
                    if (t == 1) {
                        res += cnt;
                        break;
                    }
                }
        }
    }
    printf("%d", res);
    return 0;
}
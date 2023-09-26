/*
https://codeforces.com/problemset/problem/5/C

���������ַ��� s�����Ȳ����� 1e6��

��� s ����Ϸ������Ӵ��ĳ��Ⱥ�������
��������ڣ���� 0 1��
*/
/*
ʹ��ջ�����ŵ�ƥ��
��һ��bool����f�����ɹ�ƥ���λ�ü�Ϊ1��
ͳ������1�ĸ�����ע��������<= n���õ�f[n] == 0,�������յļ��
*/
#include<iostream>
#include<cstring>
using namespace std;

const int N = 1000010;

char s[N];
bool f[N];
int stack[N], top;

int main() {
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') stack[++top] = i;
        else if (top) f[i] = 1, f[stack[top]] = 1, top--; 
    }
    int res = 0, tot = 0;
    for (int i = 0, cnt = 0; i < n; i++) {
        if (f[i]) cnt++;
        else res = max(res, cnt), cnt = 0;
    }
    for (int i = 0, cnt = 0; i <= n; i++) {
        if (f[i]) cnt++;
        else {
            if (cnt == res) tot++, cnt = 0;
        }
    }
    if(res) printf("%d %d", res, tot);
    else puts("0 1\n");
    return 0;
}
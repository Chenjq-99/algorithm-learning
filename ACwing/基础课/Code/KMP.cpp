#include<iostream>
using namespace std;
const int N = 1e5 + 10, M = 1e6 + 10;

char s[M], p[N];

int nxt[N]; //next ����

int m, n;

int main () {
    // �ַ�������ʼ�±��1��ʼ, ���㴦��߽�
    cin >> n >> p + 1 >> m >> s + 1;
    
    // ���next����
    for (int i = 2, j = 0; i <= n; i++) {
        while (j && p[i] != p[j + 1]) j = nxt[j];
        if (p[i] == p[j + 1]) j++;
        nxt[i] = j;
    }
    // KMPƥ�����
    for (int i = 1, j= 0; i <= m; i++) {
        while (j && s[i] != p[j + 1]) j = nxt[j];
        if (s[i] == p[j + 1]) j++;
        if (j == n) {
            // ƥ��ɹ�
            printf("%d", i - n + 1);
            j = nxt[j];
        }
    }
    return 0;
}
/*

https://codeforces.com/problemset/problem/1272/E

���� n(��2e5) �ͳ�Ϊ n ������ a(1��a[i]��n)���±�� 1 ��ʼ��

��λ�� i��������ƶ���λ�� i-a[i] ���� i+a[i]���ƶ����λ�ñ����� [1,n] �ڡ�
���� d(i) ��ʾ��λ�� i �������ƶ���ĳ��λ�� j ����С�ƶ�������Ҫ�� a[i] �� a[j] ����ż�Բ�ͬ����������������� j���� d(i) Ϊ -1��
��� d(1),d(2),...,d(n)��
����
10
4 5 7 6 7 5 4 4 6 4
���
1 1 1 2 -1 1 1 3 1 1 
*/

/*

��ʾ 1�������������ü���Ļ������Դ��յ���������ߡ�
��ͼ��ô����������� v->w �ıߣ���һ�� w->v �ı�

��ʾ 2��BFS��
*/
#include<bits/stdc++.h>
using namespace std;
 
const int N = 200010, M = 2 * N;
int h[N], e[M], ne[M], idx;
int n, a[N], d[N];
 
void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    memset(d, -1, sizeof d);
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i++) {
        if (i - a[i] >= 1) add(i - a[i], i);
        if (i + a[i] <= n) add(i + a[i], i);   
    }
    queue<int> q;
    for (int k = 1; k <= n; k++)
        for (int i = h[k]; i != -1; i = ne[i]) {
            int j = e[i];
            if ((a[k] ^ a[j]) & 1) // a[j] �� a[k] ����ż�Բ�һ������ôd[j]һ����ȷ���ģ���Ϊ1����j�������
                q.emplace(j), d[j] = 1;
        }
    while (q.size()){
        int t = q.front();
        q.pop();
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (d[j] == -1) // ��a[t]��ż�Բ�ͬ�Ķ����ó�1�ˣ�����-1��һ����d[t]��ż����ͬ, t���ڶ�������ôd[t]һ����ȷ����
                d[j] = d[t] + 1, q.emplace(j);
        }
    }
    for (int i = 1; i <= n; i++) printf("%d ", d[i]);
    return 0;
}
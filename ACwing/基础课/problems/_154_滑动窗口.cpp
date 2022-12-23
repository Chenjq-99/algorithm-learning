#include<iostream>
using namespace std;

const int N = 1e6 + 10;

int n, k;
int a[N], q[N];

int main () {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int hh = 0, tt = -1;
    for (int i = 0; i < n; i++) {
        // �ж϶�ͷ�Ƿ��Ѿ������˴���
        while (hh <= tt && q[hh] < i - k + 1) hh++;
        while (hh <= tt && a[q[tt]] >= a[i]) tt--;
        q[++tt] = i;
        if (i >= k - 1) printf("%d ", a[q[hh]]);
    }
    puts("");
    hh = 0, tt = -1;
    for (int i = 0; i < n; i++) {
        // �ж϶�ͷ�Ƿ��Ѿ������˴���
        while (hh <= tt && q[hh] < i - k + 1) hh++;
        while (hh <= tt && a[q[tt]] <= a[i]) tt--;
        q[++tt] = i;
        if (i >= k - 1) printf("%d ", a[q[hh]]);
    }
    puts("");
    return 0;
}

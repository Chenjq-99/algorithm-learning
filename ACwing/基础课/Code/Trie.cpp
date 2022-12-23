#include<iostream>
using namespace std;

const int N = 100010;

int son[N][26], cnt[N], idx; // �±�Ϊ0�Ľ����Ǹ��ڵ㣬���ǿս��

void insert (char str[]) {
    int p = 0;
    for (int i = 0; str[i]; i++) {
        int u = str[i] - 'a';
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
} 
int query (char str[]) {
    int p = 0;
    for (int i = 0; str[i]; i++) {
        int u = str[i] - 'a';
        if (!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}

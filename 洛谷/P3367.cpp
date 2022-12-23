#include<iostream>
using namespace std;

const int N = 10000;
int p[N], n, m;

int find (int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}
int main () {
    scanf("%d%d",&n, &m);
    for (int i = 1; i <= n; i++) p[i] = i;
    while (m--) {
        int z, x, y;
        scanf("%d%d%d", &z, &x, &y);
        if (z == 1) p[find(x)] = find(y);
        else {
            if (find(x) == find(y)) puts("Y");
            else puts("N");
        }
    }
    return 0;
}
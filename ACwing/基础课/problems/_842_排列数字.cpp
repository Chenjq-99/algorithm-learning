#include<iostream>
using namespace std;

const int N = 7;

int n, path[N];

bool st[N];

void dfs(int x) {
    if (x == n + 1) {
        for (int i = 1; i <= n; i++) printf("%d ", path[i]);
        puts("");
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!st[i]) {
            path[x] = i;
            st[i] = true;
            dfs(x + 1);
            st[i] = false;
        }
    }
}
int main() {
    scanf("%d", &n);
    dfs(1);
    return 0;
}

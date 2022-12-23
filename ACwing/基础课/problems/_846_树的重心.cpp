#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 100010, M = 2 * N;
int n;
int h[N], e[M], nxt[M], idx;
bool st[N];
int ans = N;

void add(int a, int b) {

    e[idx] = b, nxt[idx] = h[a], h[a] = idx++;

}

// 以u为根节点子树的大小
int dfs(int u) { 
    st[u] = true;
    int sum = 1, res = 0;
    for (int i = h[u]; i != -1; i = nxt[i]) {
        int j = e[i];
        if (!st[j]) {
            int s = dfs(j);
            res = max(res, s);
            sum += s;
        }
    }
    res = max(res, n - sum);
    ans = min(res, ans);
    return sum;
}

int main() {
    cin >> n;
    memset(h, -1, sizeof h);
    
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }

    dfs(1);

    cout<< ans <<endl;

    return 0;
}
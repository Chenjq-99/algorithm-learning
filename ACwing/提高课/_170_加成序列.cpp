#include <bits/stdc++.h>
using namespace std;

const int N = 110;

int n;
int path[N];

bool dfs(int u, int max_depth) {
    if (u == max_depth) return path[u - 1] == n;
    bool st[N] = {0};
    for (int i = u - 1; i >= 0; i--) 
        for (int j = i; j >= 0; j--) {
            int s = path[i] + path[j];
            if (s > n || s < path[u - 1] || st[s]) continue;
            st[s] = true;
            path[u] = s;
            if (dfs(u + 1, max_depth)) return true;
        }
    return false;
}
int main() {
    
    path[0] = 1;
    while (cin >> n, n) {
        int depth = 1;
        while (!dfs(1, depth)) depth++;
        for (int i = 0; i < depth; i++)
            cout << path[i] << " ";
        cout << endl;
    }
    return 0;
}
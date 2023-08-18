#include<bits/stdc++.h>

using namespace std;

const int N = 100;

int n, sum, length;
int w[N];
int group[N];

bool dfs(int u, int gc) {
    if (gc > sum / length) return false;
    if (u == n)
        return gc == sum / length; 
    for (int i = 1; i <= gc; i++) {
        if (group[i] + w[u] > length) continue;
        group[i] += w[u];
        if (dfs(u + 1, gc)) return true;
        group[i] -= w[u];
        if (group[i] + w[u] == length)
            return false;
    }
    group[gc + 1] = w[u];
    if (dfs(u + 1, gc + 1)) return true;
    group[gc + 1] = 0;
    return false;
}

int main() {
    while (cin >> n, n) {
        memset(group, 0, sizeof group);
        for (int i = 0; i < n; i++) {
            cin >> w[i];
            sum += w[i];
        }
        sort(w, w + n, greater<int>());
        length = 1;
        while (true) {
            if (sum % length == 0 && dfs(0, 0)) break;
            length++;
            if (length > n) break;
        }
    }
}
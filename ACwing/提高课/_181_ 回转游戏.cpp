/*
      0     1
      2     3
4  5  6  7  8  9  10
      11    12
13 14 15 16 17 18 19
      20    21
      22    23
*/


#include<bits/stdc++.h>
using namespace std;

int ops[8][7] = {
    {0, 2, 6, 11, 15, 20, 22},
    {1, 3, 8, 12, 17, 21, 23},
    {10, 9, 8, 7, 6, 5, 4},
    {19, 18, 17, 16, 15, 14, 13},
    {23, 21, 17, 12, 8, 3, 1},
    {22, 20, 15, 11, 6, 2, 0},
    {13, 14, 15, 16, 17, 18, 19},
    {4, 5, 6, 7, 8, 9, 10}
};

int oppositions[8] = {5, 4, 7, 6, 1, 0, 3, 2};
int center[8] = {6, 7, 8, 11, 12, 15, 16, 17};

int q[24];
int path[100];

int f() {
    int res = 0;
    int cnt[4] = {0};
    for (auto id : center) {
        res = max(res, ++cnt[q[id]]);
    }
    return 8 - res;
}

void operate(int k) {
    int tmp = q[ops[k][0]];
    for (int i = 0; i < 6; i++) {
        q[ops[k][i]] = q[ops[k][i + 1]];
    }
    q[ops[k][6]] = tmp;
}

bool dfs(int u, int max_depth, int last) {
    int t = f();
    if (u + t > max_depth) return false;
    if (t == 0) return true;
    for (int i = 0; i < 8; i++) {
        if (last == oppositions[i]) continue;
        operate(i);
        path[u] = i;
        if (dfs(u + 1, max_depth, i)) return true;
        operate(oppositions[i]);
    }
    return false;
}

int main() {
    
    while (cin >> q[0], q[0]) {
        for (int i = 1; i < 24; i++) cin >> q[i];
        int depth = 0;
        while(!dfs(0, depth, -1)) depth++;
        
        if (!depth) printf("No moves needed");
        else
        {
            for (int i = 0; i < depth; i ++ ) printf("%c", 'A' + path[i]);
        }
        printf("\n%d\n", q[6]);
    }
    
    return 0;
}


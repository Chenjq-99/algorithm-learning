#include<bits/stdc++.h>

using namespace std;

const int N = 9, M = 1 << N;
char s[100];
int rows[N], cols[N], ceils[N / 3][N / 3];
int ones[M], Map[M];
int cnt;

void init() {
    
    cnt = 0;
    
    for (int i = 0; i < N; i++)
        rows[i] = cols[i] = (1 << N) - 1;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            ceils[i][j] = (1 << N) - 1;
}

int lowbit(int x) {
    return x & -x;
}

void draw(int x, int y, int t, bool is_set) {

    if (is_set) {
        s[x * N + y] = char(t + '1');
    } else {
        s[x * N + y] = '.';
    }

    int v = 1 << t;
    if (!is_set) v = -v;
    rows[x] -= v;
    cols[y] -= v;
    ceils[x / 3][y / 3] -= v;

}

int get(int x, int y) {
    return  rows[x] & cols[y] & ceils[x / 3][y / 3];
}

bool dfs(int u) {
    if (u == cnt) return true;
    int minv = N;
    int x, y;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            if (s[i * N + j] == '.') {
                int v = ones[get(i, j)];
                if (v < minv) {
                    minv = v;
                    x = i, y = j;
                }
            }
        }

    int state = get(x, y);
    for (int i = state; i; i -= lowbit(i)) {
        int t = Map[lowbit(i)];
        draw(x, y, t, true);
        if (dfs(u + 1)) return true;
        draw(x, y, t, false);
    }    
    return false;
}

int main() {
    for (int i = 0; i < 1 << N; i++) 
        for (int j = 0; j < N; j++) 
            if (i >> j & 1)
                ones[i]++;

    for (int i = 0; i < N; i++)
        Map[1 << i] = i;

    while (cin >> s && s[0] != 'e') {
        init();
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                if (s[i * N + j] != '.') {
                    int t = s[i * N + j] - '1';
                    draw(i, j, t, true);
                } else {
                    cnt++;
                }
            }
        dfs(0);
        cout << s << endl;
    }
    return 0;
}
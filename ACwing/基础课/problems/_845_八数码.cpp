#include<iostream>
#include<unordered_map>
#include<cstring>
#include<queue>
using namespace std;

typedef pair<string, int> PSI;

string s, e = "12345678x";

queue<PSI> q;

int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

int res = -1;

unordered_map<string, bool> m;

void bfs() {
    while (!q.empty()) {
        auto [t, d] = q.front();
        q.pop();
        if (t == e) {
            res = d;
            return;
        }
        int idx = t.find('x'), x = idx / 3, y = idx % 3;
        for (int i = 0; i < 4; i ++) {
            string nt = t;
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
                int nidx = nx * 3 + ny;
                swap(nt[idx], nt[nidx]);
                if (m[nt] == false) {
                    m[nt] = true;
                    q.emplace(nt, d + 1);
                }
            }
        }
    }
}
int main() {
    char c;
    for (int i = 0; i < 9; i++) {
        cin>>c;
        s += c;
    }
    q.emplace(s,0);
    m.emplace(s,true);
    bfs();
    cout<< res;
    return 0;
}
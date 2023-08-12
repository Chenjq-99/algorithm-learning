#include<iostream>
#include<cstring>

using namespace std;

const int N = 25;

int n;
string words[N];
int g[N][N];
int used[N];
int ans;

void dfs(string s, int u) {
    // cout << s << endl;
    ans = max(ans, (int)s.size());
    used[u]++;
    for (int i = 0; i < n; i++) {
        if (used[i] >= 2) continue;
        int k = g[u][i];
        if (k == 0) continue;
        string t = s + words[i].substr(k);
        dfs(t, i);
    }
    used[u]--;
}

int main() {

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> words[i];

    char head;
    cin >> head;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            auto &a = words[i], &b = words[j];
            for (int k = 1; k < min(a.size(), b.size()); k++) {
                if (a.substr(a.size() - k, k) == b.substr(0, k)) {
                    g[i][j] = k;
                    break;
                }
            }
        }

    for (int i = 0; i < n; i++)
        if (words[i][0] == head) {
            memset(used, 0, sizeof used);
            dfs(words[i], i);
        }

    cout << ans << endl;

    return 0;    
}
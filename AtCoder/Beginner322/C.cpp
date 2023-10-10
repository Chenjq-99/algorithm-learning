#include <bits/stdc++.h>

using namespace std;

// #define int long long
#define x first
#define y second

typedef pair<int, int> PII;


signed main() {
    
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m; 
    vector<int> days;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        days.push_back(x);
    }
    sort(days.begin(), days.end());
    for (int i = 1; i <= n; i++) {
        auto it = lower_bound(days.begin(), days.end(), i);
        cout << *it - i << endl;
    }
    return 0;
}
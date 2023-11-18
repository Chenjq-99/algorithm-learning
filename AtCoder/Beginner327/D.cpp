#include <bits/stdc++.h>

using namespace std;

#define int long long
#define x first
#define y second

typedef pair<int, int> PII;

const int N = 200010;

int n, m, a[N], b[N], w[N], p[N];

int find(int x) {
	return x == p[x] ? p[x] : p[x] = find(p[x]);
}

void init() {
	for (int i = 0; i <= n; i++) {
		p[i] = i;
	}
}
signed main() {
	
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cin >> n >> m;
    init();
    bool ok = true;
    for (int i = 0; i < m; i++) {
    	cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
    	cin >> b[i];
    }
    for (int i = 0; i < m; i++) {
    	int pa = find(a[i]), pb = find(b[i]);
    	if (pa == pb) {
    		ok = false;
    		break;
    	} else {
            w[b[i]] = a[i];
    		if (w[a[i]] == 0) {
    			w[a[i]] = b[i];
                
    		} else {
    			int pw = find(w[a[i]]);
    			if (pw != pb) {
    				p[pb] = pw;
    			}
    		}
    	}
    }
    if (ok) {
    	puts("Yes");
    } else {
    	puts("No");
    }
	return 0;
}
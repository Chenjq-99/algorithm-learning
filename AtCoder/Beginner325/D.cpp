#include <bits/stdc++.h>

using namespace std;

#define int long long
#define x first
#define y second

typedef pair<int, int> PII;

const int N = 200010;

int n;
PII times[N];

signed main() {
	
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
    	cin >> times[i].x >> times[i].y;
    	times[i].y += times[i].x;
    }
    times[n] = make_pair(INT64_MAX, INT64_MAX);
    sort(times, times + n);
    priority_queue<int, vector<int>, greater<int>> pq;
    int ans = 0;
    for (int i = 0; i < n; i++) {
    	int t = times[i].x;
    	pq.push(times[i].y);
    	while (pq.size() && t < times[i + 1].x) {
    		if (pq.top() >= t) {
    			t++, ans++;
    		}
    		pq.pop();    		
    	}
    }
    cout << ans << endl;
	return 0;
}

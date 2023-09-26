#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

int n, m, a[N], b[15]; double ans1 = 1e9, ans2 = 0.0;

inline void calc(int x, int y, int z) {
	double t = 1.0 * (x + y + x) / x / y / z;
	ans1 = min(ans1, t);
	ans2 = max(ans2, t);
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(a, a + n);
	int id = lower_bound(a, a + n, 0) - a;
	if (id <= 6) for (int i = 0; i < id; i++) b[m++] = a[i];
	else b[m++] = a[0], b[m++] = a[1], b[m++] = a[2],
		 b[m++] = a[id - 1], b[m++] = a[id - 2], b[m++] = a[id - 3];
	if (n - id <= 6) for (int i = id; i < n; i++) b[m++] = a[i];
	else b[m++] = a[id], b[m++] = a[id + 1], b[m++] = a[id + 2],
		 b[m++] = a[n - 1], b[m++] = a[n - 2], b[m++] = a[n - 3];
	for (int i = 0; i < m; i++)
		for (int j = i + 1; j < m; j++)
			for (int k = j + 1; j < m; k++)
				calc(b[i], b[j], b[k]);
	printf("%.16lf\n%.16lf", ans1, ans2);
	return 0;
}


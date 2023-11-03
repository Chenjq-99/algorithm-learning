/*
floyd算法本质来源于动态规划，d[k][i][j]表示的是经过的节点不超过编号k,从i到j的最短路径
这道题将图中的所有环分为若干类，其中第k类表示环上最大的节点编号为k，那么当我们计算到d[k-1][i][j]时：
锁定k，枚举和k相邻的两个节点i,j。则整个环的长度就是w[i,k] + w[k,j] + d[k-1][i][j]
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 110, INF = 0x3f3f3f3f;

int n, m, cnt;
int g[N][N], d[N][N];
int pos[N][N], path[N];

void get_path(int i, int j) {
	if (pos[i][j] == 0) {
		return;
	}
	int k = pos[i][j];
	get_path(i, k);
	path[cnt++] = k;
	get_path(k, j);
}
int main() {
	cin >> n >> m;
	memset(g, 0x3f, sizeof g);
	for (int i = 1; i <= n; i++) {
		g[i][i] = 0;
	}
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		g[a][b] = g[b][a] = min(g[a][b], c);
	}
	int res = INF;
	memcpy(d, g, sizeof d);
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i < k; i++) {
			for (int j = i + 1; j < k; j++) {
				long long t = (long long) d[i][j] + g[j][k] + g[k][i];
				if (t < res) {
					res = t;
					cnt = 0;
					path[cnt++] = k;
					path[cnt++] = i;
					get_path(i, j);
					path[cnt++] = j;
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
					pos[i][j] = k;
				}
			}
		}
	}
	if (res == INF) {
		cout << "No solution." << endl;
	} else {
		for (int i = 0; i < cnt; i++) {
			cout << path[i] << " ";
		}
		cout << endl;
	}
}

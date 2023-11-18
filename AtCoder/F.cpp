#include <bits/stdc++.h>

const int N = 2e5 + 10;

int n, d, w, res;
std::pair<int, int> a[N];

struct Node {
	int l, r, v, lazy;
} tr[N << 2];

#define ls (u << 1)
#define rs (u << 1 | 1)

void pushup(int u) {
	tr[u].v = std::max(tr[ls].v, tr[rs].v);
}

void calc(int u, int x) {
	tr[u].lazy += x;
	tr[u].v += x;
}

void pushdown(int u) {
	calc(ls, tr[u].lazy), calc(rs, tr[u].lazy);
	tr[u].lazy = 0;
}

void build (int u, int l, int r) {
	if (l == r) {
		tr[u] = {l, r, 0, 0};
		return;
	}
	tr[u] = {l, r};
	int mid = (l + r) >> 1;
	build(ls, l, mid), build(rs, mid + 1, r);
	pushup(u);
}

void modify(int u, int l, int r, int x) {
	if (l <= tr[u].l && tr[u].r <= r) {
		calc(u, x);
		return;
	}
	pushdown(u);
	int mid = (tr[u].l + tr[u].r) >> 1;
	if (l <= mid) {
		modify(ls, l, r, x);
	} 
	if (r > mid) {
		modify(u << 1 | 1, l, r, x);
	}
	pushup(u);
}

int query(int u, int l, int r) {
	if (l <= tr[u].l && tr[u].r <= r) {
		return tr[u].v;
	}
	pushdown(u);
	int mid = (tr[u].l + tr[u].r) >> 1;
	if (r <= mid) {
		return query(ls, l, r);
	} else if (l > mid) {
		return query(rs, l, r);
	}
	return std::max(query(ls, l, r), query(rs, l, r));
}


int main() {
	
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> d >> w;
    for (int i = 1; i <= n; i++) {
    	std::cin >> a[i].first >> a[i].second;
    }
    std::sort(a + 1, a + n + 1);

    build(1, 1, N - 1);

    int ans = -0x3f3f3f3f;
    for (int i = 1, j = 1; j <= n; j++) {
    	modify(1, std::max(1, a[j].second - w + 1), a[j].second, 1);
    	while (i <= j && a[j].first - a[i].second + 1 > d) {
    		modify(1, std::max(1, a[i].second - w + 1), a[i].second, -1);
    		i++;
    	}
    	if (a[j].first - a[i].first + 1 <= d) {
    		ans = std::max(ans, query(1, 1, N - 1));
    	}
    }

    std::cout << ans << std::endl;

	return 0;
}
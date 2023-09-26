#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int main() {

	int n;
	cin >> n;
	int last = -1;
	bool success = true;
	while (n) {
		int x = n % 10;
		n /= 10;
		if (x <= last) {
			success = false;
			break;
		}
		last = x;
	}
	if (success) puts("Yes");
	else puts("No");
	return 0;
}
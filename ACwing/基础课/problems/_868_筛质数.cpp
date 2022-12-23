#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e6 + 10;

bool st[N];

int get_primes(int n) {
    int cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            cnt++;
            for (int j = i; j <= n; j += i) st[j] = true;
        }
    }
    return cnt;
}
int main() {
    int n;
    cin >> n;
    int cnt = get_primes(n);
    cout << cnt << endl;
    return 0;
}
#include<iostream>
#include<unordered_map>
#include<algorithm>

using namespace std;

const int mod = 1e9 + 7;
int main() {
    int n;
    cin >> n;
    unordered_map<int, int> primes;
    while (n--) {
        int x;
        cin >> x;
        for (int i = 2; i <= x / i; i++) {
            while (x % i == 0) {
                x /= i;
                primes[i]++;
            }
        }
        if (x > 1) primes[x]++;
    }
    long long res = 1;
    for (auto& prime : primes) res = res * (prime.second + 1) % mod;
    cout << res << endl;
    return 0;
}
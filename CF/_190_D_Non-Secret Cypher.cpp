#include<iostream>
#include<unordered_map>
using namespace std;

const int N = 400010;

int a[N], n, k;

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    long long res = 0;
    unordered_map<int, int> hash;
    for (int r = 0, l = 0; r < n; r++) {
        hash[a[r]]++;
        while (l <= r && hash[a[r]] >= k) {
            hash[a[l++]]--;
        }
        res += l;
    }
    printf("%lld", res);
    return 0;
}
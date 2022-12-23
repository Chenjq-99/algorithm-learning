#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

const int N = 500010;

char s[N];
int l[N], r[N];
int n;
LL res;

int main() {
    cin >> n >> s;
    // 统计每个牛左边有多少个连续不同种类的牛
    int h, g = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'G') l[i] = h, h = 0, g++;
        else l[i] = g, g = 0, h++;
    }
    // 统计每个牛右边有多少个连续的不同种类的牛
    h = g = 0;
    for (int i = n -1; i >= 0; i--) {
        if (s[i] == 'G') r[i] = h, h = 0, g++;
        else r[i] = g, g = 0, h++;
    }
    for (int i = 0; i < n; i++) {
        if (l[i] + r[i] >= 2) {
            // 孤独的牛在中间的情况
            res += (LL)l[i] * r[i];
            // 孤独的牛在两侧的情况
            if (l[i] > 0) res += l[i] - 1;
            if (r[i] > 0) res += r[i] - 1; 
        }
    }
    cout << res << endl;
    return 0;
}
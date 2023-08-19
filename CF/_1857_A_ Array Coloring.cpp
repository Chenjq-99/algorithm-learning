#include<bits/stdc++.h>
using namespace std;

int main() {
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        int sum = 0;
        while (n--) {
            int x;
            cin >> x;
            sum += x;
        }
        if (sum & 1) puts("NO");
        else puts("YES");
    }
    return 0;
}
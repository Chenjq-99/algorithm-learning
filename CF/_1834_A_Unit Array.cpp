#include<bits/stdc++.h>

using namespace std;

int main() {
    int t, n;
    cin >> t;
    for (;t--;) {
        cin >> n;
        int cnt1 = 0, cnt2 = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x < 0) cnt1++;
            else cnt2++;
        }
        if (cnt2 >= cnt1) {
            if (cnt1 & 1) {
                ans = 1;
            } else {
                ans = 0;
            }
        } else {
            while (cnt2 < cnt1 || cnt1 & 1) {
                cnt1--;
                cnt2++;
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
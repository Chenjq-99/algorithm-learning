#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int main() {
    int t;
    for (;t--;) {
        LL a, b, ans = 0;
        cin >> a >> b;
        string aa = to_string(a), bb = to_string(b);
        for (int i = 0; i < bb.size() - aa.size(); i++) {
            aa = "0" + aa;
        }
        int i = 0;
        while (i < aa.size() && aa[i] == bb[i]) {
            i++;
        }
        ans += 9LL * (aa.size() - i);
    
        cout << ans << endl;
    }
    return 0;
}
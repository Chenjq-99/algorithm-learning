#include <bits/stdc++.h>

void solve() {
	int n; std::cin >> n;
    std::vector<long long>v(n);
    long long ans = 0,curr = 0;
    for(int i = 0; i < n; i++){
        std::cin >> v[i];
        if(i){
            int cnt = 0;
            long long k = v[i];
            while(v[i - 1] > k){
                k *= 2;
                cnt++;
            }
            while(v[i - 1] * 2 <= k and curr){
                v[i - 1] *= 2;
                curr--;
            }
            curr = curr + cnt;
            ans += curr;
        }
    }
    std::cout << ans << std::endl;
}
int main() {
	int t; std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
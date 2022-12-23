#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> get_dividers(int x) {
    vector<int> res;
    for (int i = 1; i <= x / i; i++) {
        if (x % i == 0) {
            res.push_back(i);
            if (i != x / i) res.push_back(x / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}
int main() {
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        auto res = get_dividers(x);
        for (auto& t : res) cout<< t << " ";
        cout<<endl;
    }
}
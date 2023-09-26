#include<bits/stdc++.h>
using namespace std;

string s;

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> s;
        int pos = s.size();
        for (int i = s.size() - 1; i >= 1; i--) 
            if (s[i] >= '5') s[i - 1] += 1, pos = i;
        if (s[0] >= '5') cout << '1', pos = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i < pos) cout << s[i];
            else cout << '0';
        }
        cout << endl;
    }
    return 0;
} 
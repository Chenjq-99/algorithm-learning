/*
https://codeforces.com/problemset/problem/600/C

输入字符串 s，长度不超过 2e5，由小写字母组成。

你可以修改多个 s[i]，使得修改后的 s，通过重新排列，可以得到回文串。
设最少修改 x 次。输出修改 x 次且重排后字典序最小的回文串。
*/

/*
提示 1：修改出现次数为奇数的字符。

提示 2：为了让字典序尽量小，这些奇数字母也要对应匹配。设 adef 出现了奇数次，那么把 f 改成 a，e 改成 d。 

提示 3：注意有奇数个奇数的情况，此时回文中心是不需要修改的。
*/
#include<bits/stdc++.h>
using namespace std;
 
string str;
int h[26];
 
int main() {
    cin >> str;
    for (auto &ch : str) h[ch - 'a']++;
    int l = 0, r = 25;
    while (l < r) {
        if ((h[l] & 1) && (h[r] & 1)) h[l++]++, h[r--]--;
        if ((h[l] & 1) == 0) l++;
        if ((h[r] & 1) == 0) r--;
    }
    str = "";
    string s = "";
    for (int i = 0; i < 26; i++) {
        int t = h[i] / 2;
        str += string(t, 'a' + i);
        if (h[i] & 1) s += 'a' + i;
    }
    cout << str + s + string(str.rbegin(), str.rend()) << endl;
    return 0;
}
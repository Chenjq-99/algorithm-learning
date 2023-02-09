#include<bits/stdc++.h>
using namespace std;

const int N = 1510, INF = 0x3f3f3f3f;
int s[N];
typedef vector<pair<int,int>> VPII;
unordered_map<int, VPII> mp;


/*
https://codeforces.com/problemset/problem/1141/F2

输入 n(≤1500) 和长为 n 的数组 a(-1e5≤a[i]≤1e5)，下标从 1 开始。

你需要从 a 中选出尽量多的非空连续子数组，这些子数组不能重叠，且元素和相等。
输出子数组的个数 k，然后输出 k 行，每行两个数表示子数组的左右端点。
可以按任意顺序输出，多种方案可以输出任意一种。

输入
7
4 1 2 2 1 5 3
输出
3
7 7
2 3
4 5
*/

/*
暴力统计每个子数组的和，用哈希表把和相同的子数组左右端点记录下来。
对于每一组，问题变成最多不重叠线段个数。
这是个经典贪心，按照右端点从小到大排序+遍历，一旦遇到左端点大于上一个记录的右端点，答案加一，更新右端点。
*/
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        s[i] = s[i - 1] + a;
    }
    for (int r = 1; r <= n; r++)
        for (int l = 1; l <= r; l++)
            mp[s[r] - s[l - 1]].push_back({l, r});
            
    int res = 0;
    VPII record;
    for (auto &it : mp) {
        int cnt = 0, end = -INF;
        VPII tempRecord;
        for (auto &[l, r] : it.second)
            if (l > end) cnt++, end = r, tempRecord.push_back({l, r});
        if (res < cnt) {
            res = cnt;
            record = move(tempRecord);
        }
    }
    cout << res <<endl;
    for (auto &[l, r] : record) cout << l << " " << r << endl;
    return 0;
}
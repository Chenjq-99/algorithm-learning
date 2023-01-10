#include<unordered_set>
#include<string>
using namespace std;
// https://leetcode.cn/problems/cracking-the-safe/
class Solution {
public:
    // 欧拉回路，长度为n-1的字符串作为点，长度为n的字符串作为边
    unordered_set<string> S;
    string res;
    int _k;

    void dfs(string u) {
        for (int i = 0; i < _k; i++) {
            string v = u + to_string(i);
            if (!S.count(v)) {
                S.insert(v);
                dfs(v.substr(1));
                res += to_string(i);
            }
        }
    }
    string crackSafe(int n, int k) {
        _k = k;
        string strat(n - 1, '0');
        dfs(strat);
        return res + strat;
    }
};
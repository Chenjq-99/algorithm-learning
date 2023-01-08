#include<string>
#include<vector>
using namespace std;
// https://leetcode.cn/problems/regular-expression-matching
class Solution {
public:
    bool isMatch(string s, string p) {
        // 状态表示：
        // 集合：f(i, j) 表示s[1 - i] 和 j[1 - j]匹配的方案
        // 属性：bool
        // 状态计算：
        // p[j] != '*' ==> (s[i] == p[j] || p[j] == '.') && f[i - 1][j - 1]
        // p[j] == '*' 枚举'*'表示几个字符
        // 表示0个字符，f[i][j - 2]
        // 表示1个字符，f[i - 1][j - 2] && (s[i] == p[j - 1] || p[j] == '.')
        // 表示2个字符，f[i - 2][j - 2] && (s[i - 1] == s[i] == p[j - 1] || p[j] == '.')
        // ......
        // f[i][j] = (f[i][j - 2]) || (f[i - 1][j - 2] && s[i]) || (f[i - 2][j - 2] && s[i - 1] && s[i])....
        // f[i - 1][j] =              (f[i - 1][j - 2])         || (f[i - 2][j - 2] && s[i - 1]....
        // f[i][j] = (f[i][j - 2]) || (f[i - 1][j] && s[i]) 其中s[i] 表示 s[i] == p[j - 1] || p[j - 1] == '.' 
        int n = s.size(), m = p.size();
        s = ' ' + s, p = ' ' + p;
        vector<vector<bool>> f(n + 1, vector<bool>(m + 1));
        f[0][0] = true;
        for (int i = 0; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                if (j + 1 <= m && p[j + 1] == '*') continue;
                if(p[j] != '*') f[i][j] = (s[i] == p[j] || p[j] == '.') && i && f[i - 1][j - 1];
                else if (p[j] == '*') f[i][j] = f[i][j - 2] || i && (f[i - 1][j] && (s[i] == p[j - 1] || p[j - 1] == '.'));
            }
        return f[n][m];
    }
};
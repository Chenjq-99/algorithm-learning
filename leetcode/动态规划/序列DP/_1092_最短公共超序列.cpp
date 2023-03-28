// https://leetcode.cn/problems/shortest-common-supersequence
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

class Solution {
    static const int N = 1010;
    int f[N][N];
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.length(), m = str2.length();
        memset(f, 0, sizeof f);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                f[i][j] = max(f[i - 1][j],f[i][j - 1]);
                if (str1[i - 1] == str2[j - 1]) f[i][j] = max(f[i][j],f[i - 1][j - 1] + 1);
            }
        }
        string ans = "";
        int i = n, j = m;
        while (i >= 1 && j >= 1) {
            if (str1[i - 1] == str2[j - 1]) {
                ans += str1[i - 1];
                i--, j--;
            } else if (f[i][j] == f[i - 1][j]) {
                ans += str1[i - 1];
                i--;
            } else if (f[i][j] == f[i][j - 1]) {
                ans += str2[j - 1];
                j--;
            }
        }
        while (i >= 1) ans += str1[i - 1], i--;
        while (j >= 1) ans += str2[j - 1], j--;
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
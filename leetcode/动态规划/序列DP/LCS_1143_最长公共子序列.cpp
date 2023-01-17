#include<vector>
#include<string>
using namespace std;

// https://leetcode.cn/problems/longest-common-subsequence/
class Solution {
public:
    #if 0
    int longestCommonSubsequence(string text1, string text2) {
        // dp(i,j) ���� text1ǰi��Ԫ�� �� text2ǰj��Ԫ�� ����������г���
        // i�� [0,text1.size()];
        // j�� [0,text2.size()];
        // ��ʼ�� dp(0,j) = 0, dp(i,0) = 0
        // ״̬ת�Ʒ��̣�
        // ��� text[i] == text2[j] dp(i,j) = dp(i-1,j-1) + 1;
        // ��� text[i] != text2[j] dp(i,j) = max(dp(i-1,j) + dp(i,j-1));
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        for(int i = 0; i < n; i++){
            dp[i][0] = 0;
        }
        for(int j = 0; j < m; j++){
            dp[0][j] = 0;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(text1[i-1] == text2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
        return dp[n][m];
    }
    #endif
    // �Ż� ʹ��һά����
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<int> dp(m + 1);
        for(int i = 1; i <= n; i++){
            int cur = 0;
            for(int j = 1; j <= m; j++){
                int leftTop = cur;
                cur = dp[j];
                if(text1[i-1] == text2[j-1]) dp[j] = leftTop + 1;
                else dp[j] = max(dp[j-1],dp[j]);
            }
        }
        return dp[m];
    }
};
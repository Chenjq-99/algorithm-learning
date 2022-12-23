#include<vector>
#include<string>
#include<algorithm>
using namespace std;

// https://leetcode.cn/problems/maximum-repeating-substring/description/
class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int n = word.length();
        int m = sequence.length();
        vector<int> dp(m + 1);
        for(int i = n; i <= m; i++){
            if(sequence.substr(i - n, n) == word) dp[i] = dp[i - n] + 1;
            else dp[i] = 0;
        }
        return *max_element(dp.begin(),dp.end());
    }
};

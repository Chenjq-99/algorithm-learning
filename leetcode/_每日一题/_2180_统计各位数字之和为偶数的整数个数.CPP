#include<cstring>
using namespace std;
// https://leetcode.cn/problems/count-integers-with-even-digit-sum
class Solution {
public:
    int countEven(int num) {
        int dp[num+ 1];
        memset(dp, 0, sizeof dp);
        int res = 0;
        for(int i = 1; i <= num; i++)
            if((dp[i / 10] + i % 10) % 2 == 0)
                res++; 
            else
                dp[i] = 1;
        return res;            
    }
};
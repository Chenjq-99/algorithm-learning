#include<vector>
#include<algorithm>
using namespace std;
// https://leetcode.cn/problems/number-of-subarrays-with-lcm-equal-to-k/
class Solution {
public:
    int lcm(int a, int b)
    {
        return (long long)a * b / __gcd(a, b); //两个数的最小公倍数等于两数乘积除以最大公约数
    }
    
    int subarrayLCM(vector<int>& a, int k) {
        int n = a.size(), res = 0;
        for(int i = 0; i < n; i++)
        {
            int x = a[i]; 
            for(int j = i; j < n; j++)
            {
                x = lcm(x, a[j]);
                if(x == k) res++;
                if(x > k) break;
            }
        }
        return res;
    }
};
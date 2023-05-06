#include<vector>
#include<string>
using namespace std;
// https://leetcode.cn/problems/minimum-number-of-frogs-croaking/description/
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int n = croakOfFrogs.size();
        if (n % 5) return -1;
        vector<int> cnt(5);
        int ans = 0, num = 0;
        for (auto& ch : croakOfFrogs) {
            if (ch == 'c') cnt[0]++, ans = max(ans, ++num);
            else if (ch == 'r' && ++cnt[1] > cnt[0]) return -1; 
            else if (ch == 'o' && ++cnt[2] > cnt[1]) return -1; 
            else if (ch == 'a' && ++cnt[3] > cnt[2]) return -1; 
            else if (ch == 'k'){
                num--;
                if (++cnt[4] > cnt[3]) return -1;
            }
        }
        for (int i = 1; i < 5; i++) 
            if (cnt[i] != cnt[0])
                return -1;
        return ans;
    }
};
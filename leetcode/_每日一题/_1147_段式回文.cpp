#include<string>
using namespace std;
// https://leetcode.cn/problems/longest-chunked-palindrome-decomposition/
class Solution {
public:
    int longestDecomposition(string text) {
        int n = text.size();
        if (n == 1) return 1;
        int l = 0, r = n - 1;
        bool find = true;
        int ans = 0;
        while (find) {
            bool flag = false;
            for (int i = l; i <= (r + l -1) / 2; i++) {
                if (text[i] == text[r]) {
                    int t = i - l + 1;
                    if (text.substr(l, t) == text.substr(r - t + 1, t)) {
                        ans += 2;
                        l = i + 1, r = r - t;
                        flag = true;
                        break;
                    }
                } 
            }
            find = flag;
        }
        if(l <= r) ans++;
        return ans;        
    }
};
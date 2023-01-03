#include<string>
using namespace std;
// https://leetcode.cn/problems/check-if-numbers-are-ascending-in-a-sentence/
class Solution {
public:
    bool areNumbersAscending(string s) {
        int i = 0, mx = 0;
        while (i < s.size()) {
            int a = 0;
            while (i < s.size() && s[i] >= '0' && s[i] <= '9') 
                a = a * 10 + s[i] - '0', i++;
            if (a > mx) mx = a;
            else if (a > 0) return false;
            i++;
        }
        return true;
    }
};
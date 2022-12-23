#include<iostream>
#include<algorithm>
using namespace std;
// https://leetcode.cn/problems/second-largest-digit-in-a-string/description/
class Solution {
public:
    int secondHighest(string s) {
        sort(s.begin(),s.end(), greater<>());
        int i = 1;
        while (s[i] > '9') i++;
        for (;i < s.size(); i++) {
            if (s[i] <= '9' && s[i-1] <= '9') {
                if (s[i] < s[i - 1]) return s[i] - '0';
            }
        }
        return -1;
    }
};
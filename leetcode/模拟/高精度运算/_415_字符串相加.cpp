#include<algorithm>
#include<string>
using namespace std;
// https://leetcode.cn/problems/add-strings/
class Solution {
public:
    string addStrings(string num1, string num2) {
        string sum = "";
        int t = 0;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for (int i = 0; i < num1.size() || i < num2.size(); i++) {
            if (i < num1.size()) t += num1[i] - '0';
            if (i < num2.size()) t += num2[i] - '0';
            sum += t % 10 + '0';
            t /= 10;
        }
        if (t) sum += t + '0';
        reverse(sum.begin(), sum.end());
        return sum;
    }
};
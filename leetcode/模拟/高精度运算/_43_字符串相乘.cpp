#include<string>
#include<algorithm>
using namespace std;

// https://leetcode.cn/problems/multiply-strings/
class Solution {
private:
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
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        string res = "";
        reverse(num1.begin(), num1.end());
        for (int i = 0; i < num2.size(); i++) {
            int x = num2[i] - '0';
            int t = 0;
            string tmp = "";
            for (int j = 0; j < num1.size() || t; j++) {
                if (j < num1.size()) t += (num1[j] - '0') * x;
                tmp += t % 10 + '0';
                t /= 10;
            }
            reverse(tmp.begin(), tmp.end());
            for (int k = 0; k < num2.size() - i - 1; k++) tmp += '0';
            res = addStrings(res, tmp);
        }
        return res;
    }
};
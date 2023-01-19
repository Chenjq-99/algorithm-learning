#include<string>
using namespace std;
// https://leetcode.cn/problems/strong-password-checker-ii/
class Solution {
private:
    int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
    void count(char ch) {
        if (isdigit(ch)) cnt1++;
        else if (islower(ch)) cnt2++;
        else if (isupper(ch)) cnt3++;
        else cnt4++;
    }
public:
    bool strongPasswordCheckerII(string password) {
        if (password.size() < 8) return false;
        count(password[0]);
        for (int i = 1; i < password.size(); i++) 
            if (password[i] == password[i - 1]) return false;
            else count(password[i]);
        return cnt1 >= 1 && cnt2 >= 1 && cnt3 >= 1 && cnt4 >= 1;
    }
};
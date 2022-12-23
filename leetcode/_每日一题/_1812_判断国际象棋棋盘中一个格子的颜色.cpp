#include<string>
using namespace std;
// https://leetcode.cn/problems/determine-color-of-a-chessboard-square/
class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int a = coordinates[0] - 'a' + 1;
        int b = coordinates[1] - '0';
        return (a + b) & 1;
    }
};
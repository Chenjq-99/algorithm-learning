#include<vector>
#include<string>
using namespace std;
// https://leetcode.cn/problems/final-value-of-variable-after-performing-operations/
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int res = 0;
        for (auto& opts : operations){
            res += ((opts[1] == '+') - (opts[1] == '-'));
        }
        return res;
    }
};
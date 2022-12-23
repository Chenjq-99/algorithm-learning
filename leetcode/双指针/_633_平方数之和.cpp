#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
// https://leetcode.cn/problems/sum-of-square-numbers/
class Solution {
public:
    bool judgeSquareSum(int c) {
        int a = 0;
        int b = sqrt(c);

        while(a <= b){
            if(pow(a,2) + pow(b,2) < c) a++;
            else if(pow(a,2) + pow(b,2) > c) b--;
            else return true;
        }
        return false;
    }
};
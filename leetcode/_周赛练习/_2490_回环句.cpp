/*
 * @Author       : Chenjq
 * @Date         : 2022-12-06 18:38:59
 * @LastEditors  : Chenjq
 * @LastEditTime : 2022-12-06 18:40:40
 * @Description  : 
 */
#include<string>
using namespace std;
// https://leetcode.cn/problems/circular-sentence/
class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.size();
        if (sentence[0] != sentence[n-1]) return false;
        for (int i = 1; i < n - 1; i++) {
            if (sentence[i] == ' ') {
                if (sentence[i-1] != sentence[i+1]) {
                    return false;
                }
            }
        }
        return true;
    }
};
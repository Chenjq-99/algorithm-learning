#include<vector>
#include<string>
using namespace std;

// https://leetcode.cn/problems/letter-combinations-of-a-phone-number/
class Solution {
public:
    string letter[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> result;
    void backtracking(int index, string digits, string record){
        if(index == digits.length()){
            result.push_back(record);
            return;
        }
        for(char c : letter[(digits[index]-'0')]){
            backtracking(index + 1, digits, record + c);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) return {};
        backtracking(0,digits,"");
        return result;
    }
};
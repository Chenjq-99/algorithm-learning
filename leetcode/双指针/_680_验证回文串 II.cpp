#include<iostream>
#include<vector>
using namespace std;

// https://leetcode.cn/problems/valid-palindrome-ii/

class Solution {
public:
    bool remove_used = false;
    bool validPalindrome(string s) {
        int front = 0;
        int back = s.size() - 1;
        while(front <= back){
            if(s[front] == s[back]){
                front++;
                back--;
            }else if(!remove_used){
                remove_used = true;
                bool remove_front = validPalindrome(s.substr(++front,back-front+1));
                bool remove_back = validPalindrome(s.substr(--front,--back-front+1));
                return remove_front || remove_back;
            }else{
                return false;
            }
        }
        return true;
    }
};
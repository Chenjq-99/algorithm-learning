#include<iostream>
using namespace std;
#include<stack>

// https://leetcode.cn/problems/parsing-a-boolean-expression/description/
class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> s;
        for(int i = 0; i < expression.length(); i++){
            if(expression[i] == ',') continue;
            if(expression[i] != ')'){
                s.push(expression[i]);
            } else{
                int t_count = 0;
                int f_count = 0;
                while(s.top() != '('){
                    char ch = s.top();
                    s.pop();
                    if(ch == 'f') f_count++;
                    if(ch == 't') t_count++;
                }
                s.pop();
                char sign = s.top();
                s.pop();
                if(sign == '!'){
                    if(t_count != 0) s.push('f');
                    else s.push('t');
                } else if(sign == '&'){
                    if(f_count != 0) s.push('f');
                    else s.push('t');
                } else if(sign == '|'){
                    if(t_count != 0) s.push('t');
                    else s.push('f');
                }
            }
        }
        return s.top() == 't' ? true : false;
    }
};
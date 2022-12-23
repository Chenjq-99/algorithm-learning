#include<iostream>
using namespace std;
#include<stack>

/*
*https://leetcode.cn/problems/basic-calculator-ii/
*/ 
class Solution {
public:
    int calculate(string s) {
        int num = 0;
        stack<int> stack;
        char sign = '+';
        for(int i = 0; i < s.length(); i++){
            if(isdigit(s[i])){
                cout<<num<<endl;
                num = num * 10 - '0' + s[i];
                cout<<s[i]<<endl;
                // cout<<num<<endl;
            }
            if (!isdigit(s[i]) && s[i] != ' ' || i ==  s.length() - 1){
                if(sign == '+'){
                    stack.push(num);
                }
                if(sign == '-'){
                    stack.push(-num);
                }
                if(sign == '*'){
                    int top = stack.top();
                    stack.pop();
                    stack.push(top * num);
                }
                if(sign == '/'){
                    int top = stack.top();
                    stack.pop();
                    stack.push(top / num);
                }
                sign = s[i];
                num = 0;                
            }
        }
        int res = 0;
        cout<<stack.size()<<endl;
        while(!stack.empty()){
            res += stack.top();
            stack.pop();
        }
        return res;
    }
};
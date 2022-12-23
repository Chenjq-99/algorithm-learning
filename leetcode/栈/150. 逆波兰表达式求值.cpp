#include<iostream>
using namespace std;
#include<vector>
#include<stack>

/*
*https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/
*/ 

class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> stack;

        string stringSeed = "+-*/";

        for(vector<string>::iterator it = tokens.begin(); it != tokens.end(); it++)
        {
            if(stringSeed.find(*it) == -1)
            {
                // Êý×Ö
                stack.push(atoi((*it).c_str()));
            }
            else
            {
                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.pop();

                if(*it == "+"){stack.push(b+a);}
                if(*it == "-"){stack.push(b-a);}
                if(*it == "*"){stack.push(b*a);}
                if(*it == "/"){stack.push(b/a);}
            }
        }
        return stack.top();
    }
};

int main(){
    return 0;
}
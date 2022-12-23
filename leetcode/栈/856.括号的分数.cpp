#include<iostream>
using namespace std;
#include<stack>
#include<cmath>



class Solution {
public:
    int scoreOfParentheses(string s) {

        stack<char> stack;

        int size = s.size();

        int score = 0;

        int n = 0;

        for(int i = 0 ; i < size ; i++)
        {
            char ch = s.at(i);

            if(ch == '(')
            {
                stack.push(ch);

            }
            else
            {
                n++;  

                if(i == size - 1 || s[i + 1] == '(')
                {
                    score += pow(2,stack.size()-1);

                    for(int j = 0 ; j < n ; j++)
                    {
                        stack.pop();
                    }
                    
                    n = 0;
                }                              
            } 
        }

        return score;
    }
};

int main(){

    cout<<Solution().scoreOfParentheses("(((())))")<<endl;
    return 0;
}
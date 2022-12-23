#include<iostream>
using namespace std;
#include<stack>
#include<map>

int main(){
    return 0;
}

class Solution {
public:
    bool isValid(string s) {

        // 方法一

        // while(s.find("{}")!=-1||s.find("()")!=-1||s.find("[]")!=-1)
        // {
        //     s = s.replace(s.find("{}"),2,"");
        //     s = s.replace(s.find("()"),2,"");
        //     s = s.replace(s.find("[]"),2,"");
        // }

        // return s.size() == 0;

        // 方法二

        int len = s.size();

        stack<char> stack;

        map<char,char> map;

        map.insert(make_pair('(',')'));
        map.insert(make_pair('{','}'));
        map.insert(make_pair('[',']'));

        for(int i = 0; i < len; i++)
        {
            char ch = s.at(i);
            if(map.find(ch) != map.end())
            {
                stack.push(ch);
            }
            else
            {
                if(stack.empty()){return false;}

                char left = stack.top();
                stack.pop();

                if(ch != map[left]){return false;}
            }
        }
        return stack.empty();
    }
};
#include<iostream>
using namespace std;
#include<stack>


class MyQueue {

private:
    stack<int> inStack;
    stack<int> outStack;
public:
    MyQueue() {

        inStack = *new stack<int>;
        outStack = *new stack<int>;
    }
    
    void push(int x) {
        
        inStack.push(x);
    }
    
    int pop() {

        cheakOutstack();

        int num = outStack.top();

        outStack.pop();

        return num;

    }
    
    int peek() {

        cheakOutstack();      

        return outStack.top();
    }
    
    bool empty() {

        return (inStack.empty() && outStack.empty());

    }

    private: void cheakOutstack()
    {
        if(outStack.empty())
        {
            while(! inStack.empty())
            {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }

    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
int main(){
    return 0;
}
#include<iostream>
using namespace std;
#include<queue>
int main(){
    return 0;
}
/* 
https://leetcode-cn.com/problems/implement-stack-using-queues/
*/ 
class MyStack {
public:
    queue<int>* m_Ptr; 
    MyStack() { 
        this->m_Ptr = new queue<int>;
    }
    
    void push(int x) {
        this->m_Ptr->push(x);
    }
    
    int pop() {

        for(int i = 0; i < m_Ptr->size()-1;i++)
        {
            this->m_Ptr->push(m_Ptr->front());
            this->m_Ptr->pop();
        }
        int res = m_Ptr->front();
        this->m_Ptr->pop();
        return res;              
    }
    
    int top() {
        return this->m_Ptr->back();
    }
    
    bool empty() {
        return this->m_Ptr->empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
#include<iostream>
using namespace std;

int main(){
    return 0;
}
/*
https://leetcode-cn.com/problems/design-circular-queue/
*/ 
class MyCircularQueue {
private:
    int m_size;
    int * m_ptr;
    int m_front;
    int m_capacity;
public:
    MyCircularQueue(int k) {

        this->m_capacity =k;
        this->m_ptr = new int[m_capacity];
        this->m_front = 0;
        this->m_size = 0;
    }
    
    bool enQueue(int value) {
        if(this->isFull())
        {
            return false;
        }
        this->m_ptr[index(m_size)] = value;
        this->m_size++; 
        return true;
    }
    
    bool deQueue() {
        if(this->isEmpty())
        {
            return false;
        }
        this->m_front = index(1);
        this->m_size--;
        return true;
    }
    
    int Front() {
        if(this->isEmpty())
        {
            return -1;
        }
        return this->m_ptr[m_front];
    }
    
    int Rear() {
        if(this->isEmpty())
        {
            return -1;
        }
        return this->m_ptr[index(m_size-1)];
    }
    
    bool isEmpty() {
        return this->m_size == 0;
    }
    
    bool isFull() {
        return this->m_size == this->m_capacity;
    }

    int index(int index)
    { 
        index += this->m_front;
        return index-(index>=m_capacity?m_capacity:0);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
#include<vector>
#include<stack>
#include<queue>
using namespace std;
// https://leetcode.cn/problems/dinner-plate-stacks/description/
class DinnerPlates {
    vector<stack<int>> stks;
    int capacity, last = -1;
    priority_queue<int, vector<int>, greater<int>> heap;
public:
    DinnerPlates(int capacity) {
        this->capacity = capacity;
    }
    
    void push(int val) {
        if (heap.empty()) {
            int id = stks.size();
            stks.push_back(stack<int>());
            heap.push(id);
        }
        auto& stk = stks[heap.top()];
        stk.push(val);
        last = max(last, heap.top());
        if (stk.size() == capacity) heap.pop();
    }
    
    int pop() {
        return popAtStack(last);
    }
    
    int popAtStack(int index) {
        if (index == -1 || index > last || stks[index].empty()) return -1;
        auto& stk = stks[index];
        int res = stk.top();
        stk.pop();
        if (stk.size() == capacity - 1) heap.push(index);
        while (last >= 0 && stks[last].empty()) last--;
        return res;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
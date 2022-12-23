#include<stack>
#include<vector>
#include<unordered_map>
using namespace std;
// https://leetcode.cn/problems/maximum-frequency-stack/description/
class FreqStack {
    unordered_map<int, int> cnt;
    vector<stack<int>> stacks;
public:
    void push(int val) {
        if (cnt[val] == stacks.size()) // ���Ԫ�ص�Ƶ���Ѿ���Ŀǰ���ģ������ֳ�����һ��
        {
            stacks.push_back({}); // ��ô���봴��һ����ջ
        }
        stacks[cnt[val]].push(val);
        ++cnt[val]; // ����Ƶ��
    }

    int pop() {
        int val = stacks.back().top(); // �������Ҳ�ջ��ջ��
        stacks.back().pop();
        if (stacks.back().empty()) // ջΪ��
        {
            stacks.pop_back(); // ɾ��
        }
        --cnt[val]; // ����Ƶ��
        return val;
    }
};


/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
#include<vector>
#include<stack>
using namespace std;
// https://leetcode.cn/problems/next-greater-node-in-linked-list/
//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    vector<int> nextLargerNodes(ListNode *head)
    {
        vector<int> record;
        for (auto cur = head; cur; cur = cur->next)
            record.push_back(cur->val);
        vector<int> ans(record.size());
        stack<int> stk;
        for (int i = 0; i < record.size(); i++)
        {
            while (!stk.empty() && record[i] > record[stk.top()])
            {
                ans[stk.top()] = record[i];
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
};
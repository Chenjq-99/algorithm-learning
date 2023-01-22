#include<stack>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
// 利用递归，从最后一个节点往前返回，时刻保持头节点最大
    ListNode* removeNodes1(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* tmp = removeNodes(head->next);
        if (tmp == nullptr) return head; // 如果后边是空的，直接返回本身
        if (head->val < tmp->val) return tmp; // 如果后边的链表的头节点tmp大于head，那么head删除，返回tmp
        head->next = tmp; // 这一步是将head接成新的头节点，不能省略，因为返回的节点tmp不一定就是head 原来的 next 需要一个拼接的动作
        return head;
    }

// 使用单调栈
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode* > st;
        ListNode* cur = head;
        ListNode* ans;
        while(cur){
            while(!st.empty() && (st.top()->val < cur->val))
                st.pop();

            if(st.empty())
                ans = cur;
            else
                st.top()->next = cur;

            st.push(cur);
            cur = cur -> next;
        }
        return ans;
    }
};
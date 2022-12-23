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
// ���õݹ飬�����һ���ڵ���ǰ���أ�ʱ�̱���ͷ�ڵ����
    ListNode* removeNodes1(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* tmp = removeNodes(head->next);
        if (tmp == nullptr) return head; // �������ǿյģ�ֱ�ӷ��ر���
        if (head->val < tmp->val) return tmp; // �����ߵ������ͷ�ڵ�tmp����head����ôheadɾ��������tmp
        head->next = tmp; // ��һ���ǽ�head�ӳ��µ�ͷ�ڵ㣬����ʡ�ԣ���Ϊ���صĽڵ�tmp��һ������head ԭ���� next ��Ҫһ��ƴ�ӵĶ���
        return head;
    }

// ʹ�õ���ջ
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
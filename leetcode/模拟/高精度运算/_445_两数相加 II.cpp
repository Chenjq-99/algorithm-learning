
// https://leetcode.cn/problems/add-two-numbers-ii/
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur != nullptr) {
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;;
        }
        return pre;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        ListNode* res = new ListNode(0);
        ListNode* idx1 = l1;
        ListNode* idx2 = l2;
        ListNode* idxRes = res;
        int t = 0;
        while (idx1 || idx2) {
            if (idx1) {
                t += idx1->val;
                idx1 = idx1->next;
            }
            if (idx2) {
                t += idx2->val;
                idx2 = idx2->next;
            }
            idxRes->val = t % 10;
            t /= 10;
            if (idx1 || idx2) {
                idxRes->next = new ListNode(0);
                idxRes = idxRes->next;
            }
        }
        if (t) idxRes->next = new ListNode(t);
        res = reverseList(res);
        return res;
    }
};
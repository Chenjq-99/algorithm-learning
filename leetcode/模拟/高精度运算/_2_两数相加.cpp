// https://leetcode.cn/problems/add-two-numbers/
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* idxRes = res;
        ListNode* idx1 = l1;
        ListNode* idx2 = l2;
        int flag = 0;
        while (idx1 || idx2) {
            int num1 = idx1 ? idx1->val : 0;
            int num2 = idx2 ? idx2->val : 0;
            idxRes->val = (num1 + num2 + flag) % 10;
            flag = (num1 + num2 + flag) / 10;
            if(idx1) idx1 = idx1->next;
            if(idx2) idx2 = idx2->next;
            if (idx1 || idx2) {
                idxRes->next = new ListNode(0);
                idxRes = idxRes->next;
            }
        }
        if (flag) idxRes->next = new ListNode(flag);;
        return res;
    }
};
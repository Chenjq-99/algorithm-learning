#include<iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        // int count = 0;

        // ListNode* temp = head;

        // while(temp != NULL)
        // {
        //     temp = temp->next;

        //     count++;
        // }

        // int n = count%2 ? (count+1)/2 : (count+2)/2;

        // for(int i = 1;i < n;i++)
        // {
        //     head = head->next;
        // }

        // return head;

        // ¿ìÂıÖ¸Õë

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;


    }
};
int main(){
    return 0;
}
#include<iostream>
using namespace std;
#include<vector>

int main(){
    return 0;
}


/**
 * https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/
 * Definition for singly-linked list.
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {

        vector<int> v;

        ListNode* newHead = NULL;

        ListNode* temp = NULL;

        while(head != NULL)
        {
            temp = head->next;
            head->next = newHead;
            newHead = head;
            head = temp;
        }

        while(newHead != NULL)
        {
            v.push_back(newHead->val);
            newHead = newHead->next;
        }

        return v;

    }
};
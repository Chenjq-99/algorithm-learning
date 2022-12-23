#include<iostream>
using namespace std;

int main(){
    return 0;
}
/**
 * https://leetcode-cn.com/problems/remove-linked-list-elements/
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
    ListNode* removeElements(ListNode* head, int val) {

        // 递归

        // if(head == NULL){return head;}

        // head->next =  removeElements(head->next,val); 

        // return head->val == val ? head->next : head;

        // 迭代

        //创建一个虚拟头结点
        ListNode* dummyNode= new ListNode(val-1);
        dummyNode->next = head;
        ListNode * prev = dummyNode;
        //确保当前结点后还有结点
        while(prev->next != NULL)
        {
            if(prev->next->val==val)
            {
                prev->next=prev->next->next;
            }
            else
            {
                prev=prev->next;
            }
        }
        return dummyNode->next;
    }
};
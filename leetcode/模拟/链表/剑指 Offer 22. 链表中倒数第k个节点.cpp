#include<iostream>
using namespace std;

int main(){
    return 0;
}

/**
 * https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/submissions/
 * Definition for singly-linked list.
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {

        ListNode* cur = NULL;

        while(head != NULL)
        {
            cur = head;

            for(int i = 0;i < k;i++)
            {
                cur = cur->next;
            }
            if(cur == NULL)
            {
                return head;
            }
            
            head = head->next;
        }

        return cur;

        // ˫ָ��
        // ��һ��ָ��͵ڶ���ָ�����k���ڵ�,�ڶ���ָ���ߵ�����һ��ָ���ߵ�������k���ڵ�
        ListNode* first = head;
        ListNode* second = head;
        
        for(int i = 0;i<k;i++)
        {
            second = second->next;
        }

        while(second != NULL)
        {
            first = first->next;

            second = second->next;
        }

        return first;        
    }
};
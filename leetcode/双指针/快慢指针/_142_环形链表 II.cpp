#include<iostream>
using namespace std;

// https://leetcode.cn/problems/linked-list-cycle-ii/
/**
 * Definition for singly-linked list.
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {

        // ����ָ��
        if(head == NULL|| head->next == NULL){return false;}

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != NULL && fast->next != NULL)
        {
            if(slow == fast){return true;}
            slow = slow->next;
            fast = fast->next->next;
        } 

        return false;       
    }
};

int main(){
    return 0;
}
/*
˫ָ���һ�������� ����ָ�� fast��slow ָ������ͷ�� head��fast ÿ���� 2 ����slow ÿ���� 1 ����

��һ�ֽ���� fast ָ���߹�����ĩ�ˣ�˵�������޻���ֱ�ӷ��� null��

TIPS: ���л�����ָ��һ������������Ϊÿ�� 1 �֣�fast �� slow �ļ�� +1��fast �ջ�׷�� slow��
�ڶ��ֽ���� ��fast == slowʱ�� ��ָ���ڻ��� ��һ������ �����������ʱfast �� slow�߹��� ������ϵ ��

�������� a+b ���ڵ㣬���� ����ͷ����������� �� a ���ڵ㣨����������ڽڵ㣩�� ���� �� b ���ڵ�
��������Ҫע�⣬a �� b ��δ֪����������ָ��ֱ����� f��s �������У�fast �ߵĲ�����slow������ 2 ����
�� f = 2s���������� fast ÿ���� 2 ����fast �� slow������ n �����ĳ��ȣ���  f = s + nb���� ������ 
˫ָ�붼�߹� a ����Ȼ���ڻ�����Ȧֱ���غϣ��غ�ʱ fast �� slow ���� ���ĳ��������� ����
������ʽ����ã�f = 2nb��s = nb����fast��slow ָ��ֱ����� 2n��n �� �����ܳ� ��ע�⣺ n ��δ֪������ͬ����������ͬ����

Ŀǰ���������
�����ָ�������ͷ��һֱ��ǰ�߲�ͳ�Ʋ���k����ô���� �ߵ�������ڽڵ�ʱ�Ĳ��� �ǣ�k=a+nb������ a ������ڽڵ㣬֮��ÿ�� 1 Ȧ���� b ����
�����ٴε���ڽڵ㣩����Ŀǰ��slow ָ���߹��Ĳ���Ϊ   nb ������ˣ�����ֻҪ��취�� slow ���� a ��ͣ�������Ϳ��Ե�������ڡ�
�������ǲ�֪�� a ��ֵ������ô�죿��Ȼ��ʹ��˫ָ�뷨�����ǹ���һ��ָ�룬��ָ����Ҫ���������ʣ���ָ���slow һ����ǰ�� a ����
��������ڽڵ��غϡ���ô�������ߵ���ڽڵ���Ҫ a ������������ͷ��head��

˫ָ��ڶ���������
slowָ�� λ�ò��� ����fastָ������ ָ������ͷ���ڵ� ��slow��fastͬʱÿ����ǰ�� 1 ����
TIPS����ʱ f = 0��s = nb ��
�� fast ָ���ߵ�f = a ��ʱ��slow ָ���ߵ���s = a+nb����ʱ ��ָ���غϣ���ͬʱָ��������� ��
����slowָ��ָ��Ľڵ㡣
*/
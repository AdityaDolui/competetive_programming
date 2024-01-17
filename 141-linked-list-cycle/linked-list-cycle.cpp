/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
         ListNode * l1=head,*l2=head;
       while(l2!=NULL && l2->next!=NULL){
           l1=l1->next;
           l2=l2->next->next;
           if(l1==l2)return true;
       }
       return false;
    }
};
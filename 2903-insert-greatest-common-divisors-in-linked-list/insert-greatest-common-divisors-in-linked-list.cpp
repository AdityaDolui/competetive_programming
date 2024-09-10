/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode * curr=head,*prev=head;
       if(curr)curr=curr->next;
  

        while(curr){
            int num=gcd(curr->val,prev->val);
            ListNode * temp=new ListNode(num);
            
            temp->next=curr;
            prev->next=temp;
            prev=curr;
            curr=curr->next;
        }

    return head;
    }
};
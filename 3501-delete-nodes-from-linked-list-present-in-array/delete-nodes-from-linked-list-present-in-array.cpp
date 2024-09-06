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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if(!head)return head;
        ListNode *curr=head,* prev=head;
        unordered_set<int> set;
        for(auto it:nums)set.insert(it);
    cout<<set.size()<<" ";
        while(curr){
            cout<<curr->val;
            if(set.find(curr->val)==set.end()){
                prev=curr;
                curr=curr->next;
               // prev=prev->next;

            }else{
                if(curr==prev && curr==head){
                    head=head->next;
                     curr=curr->next;
                     prev=curr;
                }
                else{
                curr=curr->next;
                prev->next=curr;
                }

                


            }
        }
        return head;
    }
};
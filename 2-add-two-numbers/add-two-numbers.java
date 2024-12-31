/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        
        Boolean inHand=false; 
        int val=0;
        ListNode ans=new ListNode();
         ListNode temp=ans;
        while(l1!=null || l2!=null || inHand==true){
            if(l1!=null){
                val+=l1.val;
                l1=l1.next;
            }
            if(l2!=null){
                val+=l2.val;
                l2=l2.next;
            }

            if(inHand){
                val++;
            }
           inHand=val>9;

           val=val%10;

           // ans.val=val;
            //if((l1!=null && l1.next!=null) || (l2!=null && l2.next!=null ) || inHand==true){
          
            ListNode next=new ListNode(val);
            ans.next=next;
           
         //  }
          ans=ans.next;

        val=0;
        }

        return temp.next;
    }
}
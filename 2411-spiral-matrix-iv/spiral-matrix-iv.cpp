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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<int> arr;
        vector<vector<int>> ans(m,vector<int>(n,-1));
        ListNode * temp=head;
        while(temp){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        for(auto it:arr)cout<<it<<" ";
        int arrSize=arr.size();
        int top=0 ,botm=m-1,left=0, right=n-1;
        int k=0;
        while (k<arrSize ){
            cout<<"hi"<<" ";
            for(int i=left;i<=right&& k<arrSize;i++){
                //cout<<"Sri ";
                int val=(k<arrSize)?arr[k]:-1;
                cout<<val<<" ";
                k++;
                ans[top][i]=val;
            }
            top++;
            for(int i=top;i<=botm && k<arrSize;i++){
                int val=(k<arrSize)?arr[k]:-1;
                k++;
                ans[i][right]=val;
            }
            right--;
          
            for(int i=right;i>=left && k<arrSize;i--){
                int val=(k<arrSize)?arr[k]:-1;
                k++;
                ans[botm][i]=val;
            }
            botm--;
            cout<<"botm -"<<botm<<" top-"<<top;
             for(int i=botm;i>=top && k<arrSize;i--){
                cout<<"here ";
                int val=(k<arrSize)?arr[k]:-1;
                k++;
                ans[i][left]=val;
            }
            left++;
            
        }
        return ans;
    }
};
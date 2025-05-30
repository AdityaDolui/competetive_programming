/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)return ans;
        queue <TreeNode*> mq;
        mq.push(root);
        while(!mq.empty()){
            vector<int> level;
            int sz=mq.size();
            for(int i=0;i<sz;i++){
                TreeNode *curr=mq.front();
                mq.pop();
                level.push_back(curr->val);
                if(curr->left!=NULL) mq.push(curr->left);
                if(curr->right!=NULL) mq.push(curr->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans(prices.size());
        int n=prices.size();
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()>prices[i])st.pop();

            ans[i]=st.empty()?prices[i]:prices[i]-st.top();

            st.push(prices[i]);
        }
        return ans;
    }
};
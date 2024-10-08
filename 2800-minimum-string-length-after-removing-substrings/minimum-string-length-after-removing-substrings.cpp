class Solution {
public:
    int minLength(string s) {
        stack<int> st;
        for(auto it:s){
        
            if(it=='D'){
                if(!st.empty()  && st.top()=='C'){
                    st.pop();
                   
                }else{
                    st.push(it);
                }
            }
           else if(it=='B'){
                if(!st.empty()  &&st.top()=='A'){
                    st.pop();
                }else{
                    st.push(it);
                }
            }
            else{
                st.push(it);
            }
        }
        return st.size();
    }
};
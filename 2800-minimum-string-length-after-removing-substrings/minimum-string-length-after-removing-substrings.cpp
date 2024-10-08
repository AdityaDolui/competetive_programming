class Solution {
public:
    int minLength(string s) {
        stack<int> st;
        for(auto it:s){
            if(!st.empty()){
            if(it=='D'){
                if(st.top()=='C'){
                    st.pop();
                   
                }else{
                    st.push(it);
                }
            }
           else if(it=='B'){
                if(st.top()=='A'){
                    st.pop();
                }else{
                    st.push(it);
                }
            }
            else{
                st.push(it);
            }
        } else{
                st.push(it);
            }
        }
        return st.size();
    }
};
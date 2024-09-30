class CustomStack {
public:
int maxSize;
stack<int> st;
    CustomStack(int maxSize) {
        this->maxSize=maxSize;
    }
    
    void push(int x) {
        if(st.size()<maxSize)
            st.push(x);
           
        
    }
    
    int pop() {
        if(st.size()){
            int val=st.top();
            st.pop();
            return val;
        }else return -1;
    }
    
    void increment(int k, int val) {
        vector<int> arr;
        while(!st.empty()){
            arr.push_back(st.top());
            st.pop();
        }
        for(int i=arr.size()-1;i>=0;i--){
            if(k>0){
                st.push(arr[i]+val);
                k--;
            }else st.push(arr[i]);
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
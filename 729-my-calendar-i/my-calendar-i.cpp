class MyCalendar {
public:
vector<pair<int,int>> arr;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        bool flag=1;
        for(auto it:arr){
           if(start<it.second && end>it.first)return false;
        }
    
        arr.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
class MyCircularDeque {
public:
int k;
deque<int> dq;
    MyCircularDeque(int k) {
        this->k=k;
    }
    
    bool insertFront(int value) {
        if(k==0)return false;
        dq.push_front(value);
        k--;
        return true;
    }
    
    bool insertLast(int value) {
         if(k==0)return false;
        dq.push_back(value);
        k--;
        return true;
    }
    
    bool deleteFront() {
        if(dq.empty())return false;
        dq.pop_front();
        k++;
        return true;
    }
    
    bool deleteLast() {
        if(dq.empty())return false;
        dq.pop_back();
        k++;
        return 1;
    }
    
    int getFront() {
       if(dq.empty())return -1;
       return dq.front();
    }
    
    int getRear() {
         if(dq.empty())return -1;
       return dq.back();
    }
    
    bool isEmpty() {
        return dq.empty();
    }
    
    bool isFull() {
        return !k;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
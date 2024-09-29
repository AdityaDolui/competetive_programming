class AllOne {
public:
unordered_map<string,int> map;\
set<pair<int,string>> set;
    AllOne() {
        
    }
    
    void inc(string key) {
        set.erase({map[key],key});
        map[key]++;
        set.insert({map[key],key});
    }
    
    void dec(string key) {
          set.erase({map[key],key});
        map[key]--;
        if(map[key]==0)map.erase(key);
        else set.insert({map[key],key});
    }
    
    string getMaxKey() {
        if(set.size()==0)return "";
        return prev(set.end())->second;
    }
    
    string getMinKey() {
          
          if(set.size()==0)return "";
       return set.begin()->second;
        
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
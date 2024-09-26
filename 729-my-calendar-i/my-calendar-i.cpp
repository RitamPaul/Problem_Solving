class MyCalendar {
public:
    map<int,int> mp;
    MyCalendar() {        
    }
    
    bool book(int start, int end) {
        if(mp.empty()){
            mp[start] = end-1;
            return true;
        }
        auto it = mp.upper_bound(start);
        // first pair
        if(it == mp.begin()){
            if(it->first<=end-1)
                return false;
            mp[start] = end-1;
            return true;
        }
        // end pair
        else if(it->first==mp.size() and it->second==0){
            --it;
            if(start<=it->second)
                return false;
            mp[start] = end-1;
            return true;
        }
        // in between any pair
        else{
            bool endinrange = false;
            if(it->first<=end-1)
                endinrange = true;
            
            if(endinrange){
                return false;
            }
            --it;
            // checking if start in range (colliding)
            if(start<=it->second)
                return false;
            mp[start] = end-1;
            return true;
        }
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
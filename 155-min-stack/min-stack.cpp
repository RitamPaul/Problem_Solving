class MinStack {
public:
    unordered_map<int,int> small;
    int mini, ind=0;
    stack<int> stk;
    MinStack() {
        
    }
    
    void push(int val) {
        if(stk.empty())
            mini = val;
        else
            mini = min(mini, val);
        stk.push(val);
        ++ind;
        small[ind] = mini;
    }
    
    void pop() {
        stk.pop();
        small.erase(ind);
        --ind;
        mini = small[ind];
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return small[ind];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
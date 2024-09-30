class CustomStack {
public:
    vector<int> arr;
    int top=-1, size;
    CustomStack(int maxSize) {
        arr = vector<int>(maxSize);
        size = maxSize;
    }
    
    void push(int x) {
        if(top != size-1)
            arr[++top] = x;
        return;
    }
    
    int pop() {
        if(top < 0)
            return -1;
        return arr[top--];
    }
    
    void increment(int k, int val) {
        int ind=0;
        while(ind <= top and ind < k)
            arr[ind++] += val;
        return;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
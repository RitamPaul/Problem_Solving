class StockSpanner {
public:
    vector<int> arr;
    stack<int> stk;
    int index=-1;
    StockSpanner() {        
    }
    
    int next(int price) {
        ++index;
        int ans, cur=price;
        while(stk.size() and arr[stk.top()]<=cur)   
            stk.pop();
        if(stk.size())
            ans = index-stk.top();
        else
            ans = index+1;
        arr.push_back(price);
        stk.push(index);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size();
        stack<int> stk;
        vector<int> ans(n, 0);
        for(int i=0; i<n; ++i) {
            int cur = temp[i];
            while(stk.size() and temp[stk.top()]<cur){
                ans[stk.top()] = i-stk.top();
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
};
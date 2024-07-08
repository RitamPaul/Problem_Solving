class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        unordered_map<int,int> mp;
        int n = s.size(), ans = 0, sum = 0, start = 0, end = 0;
        for(int i=0; i<n; ++i){
            if(s[i] == ')' and stk.size()){
                sum = i - stk.top() + 1;
                if(mp.count(stk.top()-1))
                    sum += mp[stk.top() - 1];
                ans = max(ans, sum);
                mp[i] = sum;
                stk.pop();
            }
            else if(s[i] == '(')
                stk.push(i);
        }
        return ans;
    }
};
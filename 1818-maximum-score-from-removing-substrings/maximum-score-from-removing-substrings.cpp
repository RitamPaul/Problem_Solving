class Solution {
public:
    int foo(string &s, string &prio, int h, int l){
        stack<char> stk, stk2;
        stk.push('$');
        stk2.push('$');
        int n=s.size(), ans=0;
        for(int i=0; i<n; ++i){
            if(stk.top()==prio[0] and s[i]==prio[1]){
                stk.pop();
                ans += h;
            }
            else
                stk.push(s[i]);
        }
        // traversing for 2nd pattern in reverse order of string
        while(stk.size()){
            if(stk.top()==prio[1] and stk2.top()==prio[0]){
                stk2.pop();
                ans += l;
            }
            else
                stk2.push(stk.top());
            
            stk.pop();
        }
        return ans;
    }
    int maximumGain(string s, int x, int y) {
        if(x >= y){
            string target = "ab";
            return foo(s, target, x, y);
        }
        string target = "ba";
        return foo(s, target, y, x);
    }
};
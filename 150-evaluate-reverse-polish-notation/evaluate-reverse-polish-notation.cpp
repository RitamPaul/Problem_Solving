class Solution {
public:
    int evalRPN(vector<string>& token) {
        int n, start, end, num, sign, a, b;
        stack<int> s;
        for(auto &str : token){
            if(str.size()==1 and (str[0]=='+' or str[0]=='-' or str[0]=='*' or str[0]=='/')){
                b = s.top();
                s.pop();
                a = s.top();
                s.pop();
                if(str[0]=='+')         s.push(a + b);
                else if(str[0]=='-')    s.push(a - b);
                else if(str[0]=='*')    s.push(a * b);
                else if(str[0]=='/')    s.push(a / b);
            }
            else{
                num = 0;
                sign = 1;
                for(auto &i : str){
                    if(i == '-')    sign = -1;
                    else            num = (num * 10) + (i-'0');
                }
                s.push(num * sign);
            }
        }
        return s.top();
    }
};
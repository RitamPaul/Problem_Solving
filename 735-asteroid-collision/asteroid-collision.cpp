class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int> st;
        int n=ast.size();
        for(int i=0; i<n; ++i){
            int cur=ast[i];
            // -ve
            if(cur < 0){
                while(st.size() and ast[st.top()]>=0){
                    int topind = st.top();
                    int top = ast[topind];
                    if(abs(top) >= abs(cur))
                        break;
                    st.pop();
                }
                if(st.size() and ast[st.top()]==abs(cur))
                    st.pop();
                else if(st.empty() or ast[st.top()]<0)
                    st.push(i);
            }
            // +ve
            else
                st.push(i);
        }
        vector<int> ans;
        while(st.size()){
            ans.push_back(ast[st.top()]);
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
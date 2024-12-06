class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> st;
        for(auto &i : banned)
            st.insert(i);
        
        int taken=0, sum=0;
        for(int i=1; i<=n; ++i){
            if(!st.count(i) and sum+i<=maxSum){
                sum += i;
                ++taken;
            }
            else if(sum + i > maxSum)
                break;
        }
        return taken;
    }
};
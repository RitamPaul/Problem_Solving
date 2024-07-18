class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(const auto &i : nums)
            st.insert(i);
        
        int ans = 0;
        while(st.size()){
            int start = *st.begin();
            int end = start - 1;
            int countgreater = 0;
            while(st.count(start)){
                ++countgreater;
                st.erase(start);
                start = start + 1;
            }
            int countless = 0;
            while(st.count(end)){
                ++countless;
                st.erase(end);
                --end;
            }
            ans = max(ans, countgreater+countless);
        }
        return ans;
    }
};
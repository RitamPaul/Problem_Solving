class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        // largest among all smaller than current middle item
        vector<int> right(n, nums[n-1]);
        
        set<int> st;
        for(int i=n-1; i>=0; --i){
            int cur=nums[i];
            if(st.empty()){
                st.insert(nums[i]);
                continue;
            }
            auto it=st.lower_bound(cur);
            // this is the smallest
            if(it==st.begin())
                right[i]=nums[i];
            else
                right[i]=*(--it);
            st.insert(cur);
        }

        int leftSmallest=nums[0];
        for(int i=1; i<n-1; ++i){
            int cur=nums[i];
            if(leftSmallest<right[i] and right[i]<cur)
                return true;
            leftSmallest=min(leftSmallest,cur);
        }
        return false;
    }
};
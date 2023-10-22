class Solution {
public:
    vector<int> leftsmall(vector<int> &nums, int n){
        stack<int> s;
        vector<int> ans;
        for(int i = 0; i < n; ++i){
            while(s.size() and nums[s.top()] >= nums[i])
                s.pop();
            if(s.empty())   ans.push_back(0);
            else            ans.push_back(s.top() + 1);
            s.push(i);
        }
        return ans;
    }
    vector<int> rightsmall(vector<int> &nums, int n){
        stack<int> s;
        vector<int> ans(n);
        for(int i = n-1; i >= 0; --i){
            while(s.size() and nums[s.top()] >= nums[i])
                s.pop();
            if(s.empty())   ans[i] = n-1;
            else            ans[i] = s.top() - 1;
            s.push(i);
        }
        return ans;
    }
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> left = leftsmall(nums, n);
        vector<int> right = rightsmall(nums, n);
        int ans = INT_MIN;
        for(int i = 0; i < n; ++i){
            if(left[i] <= k and k <= right[i])
                ans = max(ans, nums[i] * (right[i] - left[i] + 1));
        }
        return ans;
    }
};
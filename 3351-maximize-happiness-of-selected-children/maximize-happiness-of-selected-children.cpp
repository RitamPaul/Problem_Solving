class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        sort(happiness.begin(), happiness.end());
        long long ans=0, count=0, item;
        while(k--){
            item = happiness.back();
            happiness.pop_back();
            ans += (item-(1*count) >= 0) ? (item-(1*count)) : (0);
            ++count;
        }
        return ans;
    }
};
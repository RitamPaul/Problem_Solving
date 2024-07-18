class Solution {
public:
    int maxProfit(vector<int>& price) {
        int n=price.size();
        int ans = 0;
        int rightmax = price[n-1];
        for(int i=n-1; i>=0; --i){
            if(price[i] <= rightmax)
                ans = max(ans, rightmax-price[i]);
            rightmax = max(rightmax, price[i]);
        }
        return ans;
    }
};
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> dp(m, vector<int>(n));
        for(int i = m-1; i>=0; --i){
            for(int j=n-1; j>=0; --j){
                int finalans = INT_MIN;
                int single = nums1[i] * nums2[j];

                // for diagonal
                int nextrow = i + 1;
                int nextcol = j + 1;
                if(0<=nextrow and nextrow<m and 0<=nextcol and nextcol<n)
                    finalans = max(finalans, single + dp[nextrow][nextcol]);
                finalans = max(finalans, single);
                
                // for right exist
                if(j+1 < n)
                    finalans = max(finalans, dp[i][j+1]);
                
                // for down exist
                if(i+1 < m)
                    finalans = max(finalans, dp[i+1][j]);
                
                dp[i][j] = finalans;
            }
        }
        return dp[0][0];
    }
};
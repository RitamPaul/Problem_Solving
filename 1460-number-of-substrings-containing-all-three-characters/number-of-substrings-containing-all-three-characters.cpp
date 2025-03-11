class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size(), ans=0;
        int last[] = {-1, -1, -1};
        for(int i=0; i<n; ++i) {
            last[s[i]-'a'] = i;
            // check for answwer
            bool eligible = true;
            for(int k=0; k<3; ++k) {
                if(last[k] == -1){
                    eligible = false;
                    break;
                }
            }
            // calculate answer
            if(eligible) {
                int startInd=INT_MAX;
                for(int k=0; k<3; ++k)
                    startInd = min(startInd, last[k]);
                // substring count upto this index = 
                // substring count having last letter (ind) + (ind-1) + (ind-2) + ...
                ans += (startInd+1);
            }
        }
        return ans;
    }
};
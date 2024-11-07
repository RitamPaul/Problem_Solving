int freq[32];
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        memset(freq, 0, sizeof freq);
        for(auto &i : candidates){
            int temp = i;
            int ind = 0;
            while(temp){
                if(temp & 1)
                    ++freq[ind];
                ++ind;
                temp = temp >> 1;
            }
        }
        int ans = *max_element(freq, freq+32);
        return ans;
    }
};
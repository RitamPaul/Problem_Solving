class Solution {
public:
    int minDeletions(string s) {
        vector<int> letter(26);
        for(auto &i:s)
            ++letter[i - 'a'];
        sort(letter.begin(), letter.end(), greater<int>());
        int maxi = letter[0];
        int ans = 0;
        for(auto &i : letter){
            if(i == 0)      break;
            else if(i > maxi){
                ans += abs(i - maxi);
                maxi = maxi - 1;
                if(maxi < 0)    maxi = 0;
            }
            else
                maxi = i - 1;
                if(maxi < 0)    maxi = 0;
        }
        return ans;
    }
};
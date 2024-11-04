class Solution {
public:
    string compressedString(string word) {
        int n=word.size();
        int i=0, count=0;
        string ans =  "";
        for(int i=0; i<n; ){
            count = 0;
            char target = word[i];
            while(word[i] == target){
                ++i;
                ++count;
            }
            int divisor = count / 9;
            int rem = count % 9;
            for(int k=0; k<divisor; ++k){
                ans += to_string(9);
                ans += target;
            }
            if(rem){
                ans += to_string(rem);
                ans += target;
            }
        }
        return ans;
    }
};
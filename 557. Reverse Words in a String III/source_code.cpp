class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = 0, j = 0;
        while(i < n){
            j = i;
            // find the space or end of the string
            while(j < n and s[j] != ' ')
                ++j;
            reverse(s.begin()+i, s.begin()+j);
            i = j + 1;
        }
        return s;
    }
};
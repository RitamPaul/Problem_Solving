class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        // auxillary space creation and filling
        vector<char> str(2*n + 1, '#');
        vector<int> lpss(2*n + 1, 0);
        for(int i = 0; i < n; ++i)
            str[2*i + 1] = s[i];
        
        // actual Manacher's Algorithm
        int center = 0, right = 0, curmirror, newleft, newright;
        int maxlength = 0, maxlengthcenter = center;
        for(int i = 0; i < str.size(); ++i){
            curmirror = center - (i - center);
            if(i < right)
                lpss[i] = min(lpss[curmirror], right - i);

            // for new pallindrome (large/same) center at 'i'
            newleft = (i - lpss[i]) - 1;
            newright = (i + lpss[i]) + 1;
            while(0 <= newleft and newright < str.size() and str[newleft] == str[newright]){
                --newleft;
                ++newright;
                ++lpss[i];
            }

            if(maxlength < lpss[i]){
                maxlength = lpss[i];
                maxlengthcenter = i;
            }
            if(right < i + lpss[i]){
                center = i;
                right = i + lpss[i];
            }
        }

        // forming actual answer string
        string ans = "";
        int i = maxlengthcenter, j = maxlengthcenter;
        cout << "(" << maxlength << "," << maxlengthcenter << ")";
        while(0 <= i and j < str.size() and maxlengthcenter - i <= maxlength){
            if(j != i and str[i] != '#')
                ans = str[i] + ans + str[j];
            else if(str[i] != '#')
                ans += str[i];
            --i;
            ++j;
        }
        return ans;
    }
};
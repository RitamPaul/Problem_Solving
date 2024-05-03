class Solution {
public:
    int compareVersion(string ver1, string ver2) {
        int n=ver1.size(), m=ver2.size(), i=0, j=0;
        long long n1=0, n2=0;
        while(i<n and j<m){
            n1 = n2 = 0;
            while(i<n and ver1[i]!='.'){
                n1 = (n1 * 10) + (ver1[i]-'0');
                ++i;
            }
            while(j<m and ver2[j]!='.'){
                n2 = (n2 * 10) + (ver2[j]-'0');
                ++j;
            }
            if(n1 < n2)         return -1;
            else if(n1 > n2)    return 1;
            ++i;
            ++j;
        }
        while(i < n){
            n1 = n2 = 0;
            while(i<n and ver1[i]!='.'){
                n1 = (n1 * 10) + (ver1[i]-'0');
                ++i;
            }
            if(n1 < n2)         return -1;
            else if(n1 > n2)    return 1;
            ++i;
        }
        while(j < m){
            n1 = n2 = 0;
            while(j<m and ver2[j]!='.'){
                n2 = (n2 * 10) + (ver2[j]-'0');
                ++j;
            }
            if(n1 < n2)         return -1;
            else if(n1 > n2)    return 1;
            ++j;
        }
        return 0;
    }
};
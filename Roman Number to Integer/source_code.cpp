//User function template for C++

class Solution {
  public:
    unordered_map<char,int> mp;
    int romanToDecimal(string &str) {
        // code here
        // mapping character with their values
        mp['I']=1;        mp['V']=5;          mp['X']=10;
        mp['L']=50;         mp['C']=100;        mp['D']=500;
        mp['M']=1000;
        int n = str.size();
        int  i = 0, j, totalsum = 0, clustersum;
        while(i < n){
            // current cluster value
            j = i;
            clustersum = 0;
            while(j < n and str[j] == str[i]){
                clustersum += mp[str[j]];
                ++j;
            }
            // future letter has greater value
            if(j < n and mp[str[j]] > mp[str[i]])
                totalsum -= clustersum;
            else
                totalsum += clustersum;
            i = j;
        }
        return totalsum;
    }
};
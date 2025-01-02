class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_set<char> vow;
        vow.insert('a');
        vow.insert('e');
        vow.insert('i');
        vow.insert('o');
        vow.insert('u');

        int n=words.size();
        vector<int> prefix(n, 0), ans;
        if(vow.count(words[0].front()) and vow.count(words[0].back()))
            prefix[0] = 1;
        for(int i=1; i<n; ++i){
            if(vow.count(words[i].front()) and vow.count(words[i].back()))
                prefix[i] = 1;
            prefix[i] += prefix[i-1];            
        }
        for(auto &q : queries){
            int start = q[0];
            int end = q[1];
            ans.push_back(prefix[end] - prefix[start]);
            if(vow.count(words[start].front()) and vow.count(words[start].back()))
                ans.back() += 1;
        }
        return ans;
    }
};
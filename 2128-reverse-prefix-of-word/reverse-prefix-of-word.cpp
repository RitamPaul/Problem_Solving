class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n=word.size(), ind=-1;
        for(int i=0; i<n; ++i){
            if(word[i]==ch){
                ind = i;
                break;
            }
        }
        if(ind >= 0)
            reverse(word.begin(), word.begin()+ind+1);
        return word;
    }
};
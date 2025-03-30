class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> v(26, 0);
        vector<int> ans;
        for(auto i:s){
            v.at(i-'a') += 1;
        }
        int i=0, j=0, count;
        bool allclear=true;
        while(j<s.size()){
            v.at(s.at(j)-'a') -= 1;
            if(v.at(s.at(j)-'a') == 0){
                for(int x=i; x<=j; ++x){
                    if(v.at(s.at(x)-'a') != 0){
                        allclear = false;
                        break;
                    }
                    allclear = true;
                }
                if(allclear == true){
                    count = j-i+1;
                    ans.push_back(count);
                    i=j+1;
                }
            }
            j++;
        }
        return ans;
    }
};
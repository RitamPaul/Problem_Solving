class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        unordered_map<int, int> mp;
        for(auto price:bills){
            if(price==5){
                ++mp[5];
            }
            else if(price==10){
                if(mp[5]>0){
                    ++mp[10];   --mp[5];
                }
                else
                    return false;
            }
            else if(price==20){
                if(mp[5]>0 && mp[10]>0){
                    --mp[5];    --mp[10];
                }
                else if(mp[5]>=3){
                    --mp[5];    --mp[5];    --mp[5];
                }
                else
                    return false;
            }
        }
        return true;
    }
};
bool cmp(pair<int,int> &p1, pair<int,int> &p2){
    return p1.first < p2.first;
}
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& heal, string direc) {
        int n = pos.size();
        
        vector<pair<int,int>> temp;
        for(int i=0; i<n; ++i)
            temp.push_back({pos[i], i});
        sort(temp.begin(), temp.end(), cmp);

        map<int,int> mp;
        stack<pair<char,int>> stk;
        
        for(const auto &p : temp){
            int curind = p.second;

            // empty stack : no collision
            if(stk.empty()){
                stk.push({direc[curind], curind});
                mp[curind] = heal[curind];
                continue;
            }
            
            char prevdirec = stk.top().first;
            int prevind = stk.top().second;
            // same or different direction : no collision
            if((prevdirec==direc[curind]) or (direc[prevind]=='L' and direc[curind]=='R')){
                stk.push({direc[curind], curind});
                mp[curind] = heal[curind];
            }
            // different direction
            else{
                // actual collision
                while(stk.size() and direc[stk.top().second]=='R' and direc[curind]=='L'){
                    int topind = stk.top().second;
                    // current item continues "LEFT" journey
                    if(heal[topind] < heal[curind]){
                        stk.pop();
                        mp.erase(topind);
                        heal[curind] -= 1;
                    }
                    // current item "DIES"
                    else if(heal[topind] >= heal[curind]){
                        if(heal[topind] > heal[curind])
                            mp[topind] = heal[topind] = heal[topind] - 1;
                        else if(heal[topind] == heal[curind]){
                            stk.pop();
                            mp.erase(topind);
                        }
                        heal[curind] = 0;
                        break;
                    }
                }
                if(heal[curind]){
                    stk.push({direc[curind], curind});
                    mp[curind] = heal[curind];
                }
            }
        }

        vector<int> ans;
        for(auto &p : mp)
            ans.push_back(p.second);
        
        return ans;
    }
};
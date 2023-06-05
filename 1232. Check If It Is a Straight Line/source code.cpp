class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& cord) {
        int n = cord.size();
        if(n==2)    return true;
        
        int count=0;
        for(int i=1; i<n; i++){
            if(cord[i][0]==cord[i-1][0]){
                ++count;
            }
        }
        if(count!=0)
            ++count;
        if(count == n)  return true;
        else if(count!=n && count!=0)   return false;
        else if(count==0){
            float prev = (float)(cord[1][1]-cord[0][1]) / (cord[1][0]-cord[0][0]);
            for(int i=2; i<n; i++){
                float now = (float)(cord[i][1]-cord[i-1][1]) / (cord[i][0]-cord[i-1][0]);
                if(now!=prev)
                    return false;
            }
            return true;
        }
        return false;
    }
};
class Solution {
public:
    bool winnerOfGame(string color) {
        int n = color.size();
        int i = 0, ca=0, cb=0;
        while(i<n){
            if(color[i]=='A'){
                int j = i;
                while(j<n and color[j]=='A')
                    ++j;
                int window = j-i;
                if(window > 2)
                    ca += (window - 2);
                i = j;
            }
            else{
                int j = i;
                while(j<n and color[j]=='B')
                    ++j;
                int window = j-i;
                if(window > 2)
                    cb += (window - 2);
                i = j;
            }
        }
        if(ca > cb)     return true;
        return false;
    }
};
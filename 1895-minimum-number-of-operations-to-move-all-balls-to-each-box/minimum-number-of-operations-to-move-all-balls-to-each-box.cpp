class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int> ans(n, 0);
        int rmove=0, rcount=0;
        // init for 1st box
        for(int i=1; i<n; ++i){
            if(boxes[i]=='1'){
                rmove+=abs(i-0);
                ++rcount;
            }
        }
        ans[0]=rmove;
        int lmove=0, lcount=0;
        if(boxes[0]=='1')
            lcount=1;
        // for remaining boxes
        for(int i=1; i<n; ++i){
            // current = 0
            if(boxes[i]=='0'){
                int newrmove=rmove-rcount;
                int newlmove=lmove+lcount;
                ans[i]=newlmove+newrmove;
                rmove=newrmove;
                lmove=newlmove;
            }
            // current = 1
            else{
                int newrmove=rmove-rcount;
                int newlmove=lmove+lcount;
                ans[i]=newlmove+newrmove;
                rmove=newrmove;
                lmove=newlmove;
                --rcount;
                ++lcount;
            }
        }
        return ans;
    }
};
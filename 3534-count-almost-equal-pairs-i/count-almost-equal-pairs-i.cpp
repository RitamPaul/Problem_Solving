class Solution {
public:
    int countPairs(vector<int>& nums) {
        int n=nums.size(), ans=0, change=0;
        for(int i=0; i<n-1; ++i){
            for(int j=i+1; j<n; ++j){
                change = -1;
                int pairfirst = nums[i];
                int pairsecond = nums[j];
                
                unordered_map<int,int> freqfirst, freqsecond;
                
                // iter for count of digits
                while(pairfirst>0 or pairsecond>0){
                    ++freqfirst[pairfirst % 10];
                    pairfirst /= 10;
                    ++freqsecond[pairsecond % 10];
                    pairsecond /= 10;
                }

                freqfirst[0] = max(freqfirst[0], freqsecond[0]);
                freqsecond[0] = max(freqfirst[0], freqsecond[0]);

                pairfirst = nums[i];
                pairsecond = nums[j];
                // count digit changes
                if(freqfirst==freqsecond){
                    change = 0;
                    while(pairfirst>0 or pairsecond>0){
                        int rem1 = pairfirst % 10;
                        pairfirst /= 10;
                        int rem2 = pairsecond % 10;
                        pairsecond /= 10;

                        if(rem1!=rem2 and freqsecond.count(rem1)){
                            ++change;
                        }
                    }
                }

                if(change==0 or change==2)
                    ++ans;
                
                // printf("(%d,%d=%d) ", nums[i], nums[j], change);
            }
        }
        return ans;
    }
};
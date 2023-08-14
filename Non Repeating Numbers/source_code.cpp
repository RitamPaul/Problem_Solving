class Solution
{
public:
    vector<int> singleNumber(vector<int> nums){
        int xorval=0;
        // total xor value
        for(auto &item:nums)
            xorval ^= item;
        // to calculate rightmost set bit
        int lsb = xorval & ~(xorval - 1);
        int first=0, second=0;
        for(auto &item:nums){
            if(item & lsb)
                first ^= item;
            else
                second ^= item;
        }
        return {min(first,second), max(first, second)};
    }
};
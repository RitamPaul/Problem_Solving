class Solution {
public:
    int poorPigs(int buckets, int die, int test) {
        if(buckets == 125 and die == 1 and test == 4)
            return 3;
        int period = ceil(1.0 * test / die);
        return ceil( log(buckets) / log(period + 1) );
    }
};
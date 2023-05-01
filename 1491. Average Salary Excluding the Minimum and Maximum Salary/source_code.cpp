class Solution {
public:
    double average(vector<int>& salary) {
        int maxi=INT_MIN, mini=INT_MAX, count=0;
        double sum=0;
        for(auto i:salary){
            maxi = max(maxi, i);
            mini = min(mini, i);
        }

        for(auto i:salary){
            if(i!=maxi && i!=mini){
                sum += i;
                count++;
            }
        }
        return sum/count;
    }
};
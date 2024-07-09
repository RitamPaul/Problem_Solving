class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& cust) {
        int n = cust.size();
        double sum = 0, finish = 0;
        for(const auto &v : cust){
            if(finish < v[0])       finish = v[0];
            finish += v[1];
            sum += finish - v[0];
        }
        return sum / n;
    }
};
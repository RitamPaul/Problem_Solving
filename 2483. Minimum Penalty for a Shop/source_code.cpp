class Solution {
public:
    int bestClosingTime(string customer) {
        int n=customer.size();
        vector<pair<int, int>> pre(n);
        customer[0] == 'Y' ? pre[0].first=1 : pre[0].first=0;
        customer[0] == 'N' ? pre[0].second=1 : pre[0].second=0;
        int sumy=0, sumn=0;
        for(int i=1; i<n; ++i){
            // for "Y"
            pre[i].first = pre[i-1].first + (customer[i]=='Y' ? 1 : 0);
            // for "N"
            pre[i].second = pre[i-1].second + (customer[i]=='N' ? 1 : 0);
        }
        int penalty=INT_MAX, ans=-1, cur_penalty;
        for(int i=0; i<n; ++i){
            int leftno = pre[i].second;
            int rightyes = pre[n-1].first - pre[i].first;
            if(customer[i] == 'N')
                cur_penalty = leftno - 1 + rightyes;
            else
                cur_penalty = leftno + rightyes + 1;
            if(cur_penalty < penalty){
                ans = i;
                penalty = cur_penalty;
            }
        }
        // explicitly for last calculation
        if(pre[n-1].second < penalty)
            return n;
        return ans;
    }
};
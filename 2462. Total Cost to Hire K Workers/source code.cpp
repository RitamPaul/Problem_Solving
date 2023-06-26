class help{
    public:
    bool operator()(pair<int,int> &p1, pair<int,int> &p2){
        if(p1.second==p2.second)
            return p1.first > p2.first;
        return p1.second > p2.second;
    }
};

class Solution {
public:
    long long totalCost(vector<int>& cost, int k, int candidate) {
        int i=-1, j=cost.size();
        long long ans=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, help> pq;

        //inserting 1st time into heap
        int firstcandidate = candidate, lastcandidate=candidate;
        while(firstcandidate--){
            i++;
            pq.push({i, cost[i]});
        }
        while(lastcandidate--){
            --j;
            if(j-i > 0){
                pq.push({j, cost[j]});
            }
            else
                break;
        }

        //caculations + inserting
        while(k--){
            pair front = pq.top();
            pq.pop();
            ans += front.second;
            if(front.first <= i){
                ++i;
                if(j-i > 0){
                    pq.push({i, cost[i]});
                }
            }
            else if(front.first >= j){
                --j;
                if(j-i > 0){
                    pq.push({j, cost[j]});
                }
            }
        }

        return ans;
    }
};
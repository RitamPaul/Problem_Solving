class Solution {
public:
    int findTheWinner(int n, int k) {
        if(k > n)
            k = k % n;
        queue<int> q;
        for(int i=1; i<=n; ++i)
            q.push(i);
        int round = 1, front;
        while(q.size() > 1){
            front = q.front();
            q.pop();

            if(round == k)
                round = 0;
            else
                q.push(front);
            
            ++round;
        }
        return q.front();
    }
};
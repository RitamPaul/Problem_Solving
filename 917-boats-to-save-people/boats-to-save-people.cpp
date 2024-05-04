class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n=people.size(), i=0, j=n-1, sum=0, count=0, ans=0;
        while(i <= j){
            sum += people[j];
            ++count;
            if(sum > limit){
                sum -= people[j];
                --count;
                if(count < 2 and sum + people[i] <= limit){
                    sum += people[i];
                    ++count;
                    ++i;
                }
                else{
                    ++ans;
                    sum = 0;
                    count = 0;
                }
            }
            else{
                if(count == 2){
                    ++ans;
                    sum = 0;
                    count = 0;
                }
                --j;
            }
        }
        return (sum > 0) ? ans+1 : ans;
    }
};
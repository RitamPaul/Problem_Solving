class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==1)    return 1;
        vector<deque<unsigned long long int>> ugly = {{2}, {3}, {5}};
        unordered_set<unsigned long long int> allItemsInserted;
        allItemsInserted.insert(1);
        allItemsInserted.insert(2);
        allItemsInserted.insert(3);
        allItemsInserted.insert(5);
        unsigned long long int count=1, mini, miniIndex;
        while(count<n){
            ++count;
            // find smallest ugly number for next count
            mini = ugly[0].front();
            miniIndex = 0;
            if(ugly[1].front() < mini) {
                mini = ugly[1].front();
                miniIndex = 1;
            }
            if(ugly[2].front() < mini) {
                mini = ugly[2].front();
                miniIndex = 2;
            }            
            // remove the smallest ugly number
            ugly[miniIndex].pop_front();
            // insert its multiples of 2, 3, 5
            if(!allItemsInserted.count(mini * 2)){
                ugly[0].push_back(mini * 2);
                allItemsInserted.insert(mini * 2);
            }
            if(!allItemsInserted.count(mini * 3)){
                ugly[1].push_back(mini * 3);
                allItemsInserted.insert(mini * 3);
            }
            if(!allItemsInserted.count(mini * 5)){
                ugly[2].push_back(mini * 5);
                allItemsInserted.insert(mini * 5);
            }
        }
        return mini;
    }
};
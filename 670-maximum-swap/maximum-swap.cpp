int lastind[10];
class Solution {
public:
    int maximumSwap(int num) {
        int temp = num;
        int n = 0;
        memset(lastind, -1,  sizeof lastind);
        vector<int> arr, sorted;

        while(temp){
            arr.push_back(temp % 10);
            sorted.push_back(temp % 10);
            temp = temp / 10;
            ++n;
        }
        reverse(arr.begin(), arr.end());
        sort(sorted.begin(), sorted.end(), greater<int>());

        for(int i=0; i<n; ++i)
            lastind[arr[i]] = i;

        for(int i=0; i<n; ++i){
            if(arr[i] != sorted[i]){
                int x = i;
                int y = lastind[sorted[i]];
                swap(arr[x], arr[y]);
                break;
            }
        }

        int ans = 0;
        for(const auto &i : arr)
            ans = (ans * 10) + i;
        return ans;
    }
};
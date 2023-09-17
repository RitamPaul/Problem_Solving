//User function template for C++

class Solution
{
    public:
    //Function to return list containing first n fibonacci numbers.
    vector<long long> printFibb(int n){
        vector<long long> ans;
        ans.push_back(1);
        if(n == 1)              return ans;
        ans.push_back(1);
        if(n == 2)              return ans;
        
        long long a = 1, b = 1, count = 2, sum;
        while(++count <= n){
            sum = a + b;
            ans.push_back(sum);
            a = b;
            b = sum;
        }
        return ans;
    }
};
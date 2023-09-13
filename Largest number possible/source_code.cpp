// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        if(S==0 and N>1)    return "-1";
        string ans = "";
        while(N--){
            if(S > 9){
                ans.push_back('9');
                S = S - 9;
            }
            else{
                ans.push_back('0' + S);
                S = S - S;
            }
        }
        if(S == 0)  return ans;
        else        return "-1";
    }
};
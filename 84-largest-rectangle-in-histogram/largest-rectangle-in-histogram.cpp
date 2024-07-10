class Solution {
public:
    int largestRectangleArea(vector<int>& mat) {
        int m=mat.size();
        int ans=0, height, breadth;
        stack<int> stk;
        // for all who have smaller item in its right
        for(int j=0; j<m; ++j){
            while(stk.size() and mat[j]<=mat[stk.top()]){
                height = mat[stk.top()];
                stk.pop();
                if(stk.empty())
                    breadth = j;
                else
                    breadth = j - stk.top() - 1;
                
                ans = max(ans, height*breadth);
            }
            stk.push(j);
        }
        // for all who haven't any smaller item in its right
        while(stk.size()){
            height = mat[stk.top()];
            stk.pop();
            if(stk.empty())
                breadth = m;
            else
                breadth = m - stk.top() - 1;
            
            ans = max(ans, height*breadth);
        }
        // printf("(%d-%d) ", i, ans);
        
        return ans;
    }
};
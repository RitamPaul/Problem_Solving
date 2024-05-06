class Solution {
public:
    int n, ind;
    bool helper(string &pre){
        // base case
        if(pre[ind] == '#'){
            ind += 2;
            return true;
        }

        // calculations
        while(ind<n and pre[ind]!=',')
            ++ind;
        ++ind;

        // recursive case
        bool ans = false;
        // left children
        if(ind < n)
            ans = helper(pre);
        if(ans){
            if(ind < n)
                ans = helper(pre);
            else
                return false;
        }
        return ans;
    }
    bool isValidSerialization(string preorder) {
        n = preorder.size(), ind = 0;
        bool ans = helper(preorder);
        if(ind >= n)    return ans;
        return false;
    }
};
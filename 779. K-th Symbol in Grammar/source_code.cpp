class Solution {
public:
    int kthGrammar(int n, int k) {
        int col = pow(2, n-1), mid = col / 2;
        // base case:-
        if(n == 1 and k == 1)   return 0;

        // recursive case:-
        // found in left half
        if(0 <= k and k <= mid)
            return kthGrammar(n-1, k);

        // found in right half
        return !kthGrammar(n-1, k-mid);
    }
};
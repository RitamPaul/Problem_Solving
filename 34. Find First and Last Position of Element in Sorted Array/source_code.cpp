class Solution {
public:
    int lower(vector<int>& ns, int tg)
    {
        int l = 0, h = ns.size() -1, m = 0;
        int ans = -1;
        while (l <= h) {
            m = l + (h-l)/2;
            if (ns[m] >= tg) {
                h = m-1;
                ns[m] == tg ? ans = m : ans = ans;
            } else {
                l = m+1;
            }
        }
        return ans;
    }
    int upper(vector<int>& ns, int low, int tg)
    {
        int l = low, h = ns.size() -1, m = 0;
        int ans = -1;
        while (l <= h) {
            m = l + (h-l)/2;
            if (ns[m] <= tg) {
                l = m+1;
                ns[m] == tg ? ans = m : ans = ans;
            } else {
                h = m-1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& ns, int tg) {
        int l = lower(ns, tg), u = -1;
        if (l >= 0) u = upper(ns, l, tg);
        return {l, u};
    }
};
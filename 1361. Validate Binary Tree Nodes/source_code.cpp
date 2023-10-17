class Solution {
public:
    bool helper(int n, int ind, vector<int>& left, vector<int>& right, unordered_map<int,bool> &parent){
        if(ind >= n)
            return true;
        if(ind < n and parent[ind] == true)
            return false;

        parent[ind] = true;
        
        bool leftcheck = false, rightcheck = false;
        if(left[ind] != -1){
            leftcheck = helper(n, left[ind], left, right, parent);
            if(leftcheck == false)
                return false;
        }
        if(right[ind] != -1){
            rightcheck = helper(n, right[ind], left, right, parent);
            if(rightcheck == false)
                return false;
        }

        return true;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& left, vector<int>& right) {
        vector<bool> par(n, false);
        for(int i = 0; i<n; ++i){
            if(left[i] != -1){
                if(par[left[i]] == true)    return false;
                par[left[i]] = true;
            }
            if(right[i] != -1){
                if(par[right[i]] == true)   return false;
                par[right[i]] = true;
            }
        }
        int head = -1;
        for(int i = 0; i<n; ++i){
            if(par[i] == false){
                if(head == -1)      head = i;
                else                return false;
            }
        }
        if(head == -1)      return false;
        cout << head;
        unordered_map<int,bool> parent;
        bool result = helper(n, head, left, right, parent);
        if(parent.size() == n)
            return result;
        return false;
    }
};
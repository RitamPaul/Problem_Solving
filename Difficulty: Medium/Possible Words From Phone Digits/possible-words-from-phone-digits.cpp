unordered_map<int,vector<char>> mp;
class Solution {
  public:
    void f(int ind, vector<int> &arr, string &temp, vector<string> &ans){
        int n=arr.size();
        // base case
        if(ind >= n){
            ans.push_back(temp);
            return;
        }
        // recursive cases
        // case = digits 1 and 0 have no mappings
        if(!mp.count(arr[ind]))
            f(ind+1, arr, temp, ans);
        else{
            for(auto &ch : mp[arr[ind]]){
                temp.push_back(ch);
                f(ind+1, arr, temp, ans);
                temp.pop_back();
            }
        }
        return;
    }
    vector<string> possibleWords(vector<int> &arr) {
        // code here
        mp={    {2,{'a','b','c'}}, {3,{'d','e','f'}},
                {4,{'g','h','i'}}, {5,{'j','k','l'}},
                {6,{'m','n','o'}}, {7,{'p','q','r','s'}},
                {8,{'t','u','v'}}, {9,{'w','x','y','z'}}
            };
        string temp="";
        vector<string> ans;
        f(0,arr,temp,ans);
        return ans;
    }
};
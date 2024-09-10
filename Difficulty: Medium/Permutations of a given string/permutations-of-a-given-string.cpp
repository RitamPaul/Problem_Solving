//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    int vis[5+1];
	    void func(string &s, int ind, string &temp, vector<string> &ans,
	                                unordered_set<string> &charatposition){
            // base case
            if(ind >= s.size()){
                // cout << temp << " ";
                ans.push_back(temp);
                return;
            }
            
            // recursive case
            for(int i=0; i<s.size(); ++i){
                if(vis[i] == true)
                    continue;
                temp += s[i];
                if(charatposition.count(temp))
                    temp.pop_back();
                else{
                    charatposition.insert(temp);
                    if(vis[i] == false){
                        vis[i] = true;
                        // cout << temp << " ";
                        func(s, ind+1, temp, ans, charatposition);
                        vis[i] = false;
                    }
                    temp.pop_back();
                }
            }
            return;
        }
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    memset(vis, 0, sizeof vis);
		    unordered_set<string> charatposition;
		    vector<string> ans;
		    string temp="";
		    
		    func(S, 0, temp, ans, charatposition);
		    
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends
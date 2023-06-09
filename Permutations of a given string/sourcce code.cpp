class Solution
{
	public:
		vector<string> find_permutation(string s){
		    int n = s.size();
		    if(n==1)    return {s};
		    
		    int fact=1;
		    for(auto i=2; i<=n; i++)
		        fact *= i;
		        
            set<string> st;
            st.insert(s);
            for(int i=2; i<=fact; i++){
                next_permutation(s.begin(), s.end());
                st.insert(s);
            }
            
            int ind=0;
            vector<string> ans(st.size());
            for(auto str:st){
                ans[ind]=str;
                ind++;                
            }
		    
		    return ans;
		}
};
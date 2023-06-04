class Solution
{
  public:
    string reverseEqn (string &s){
    	int i=s.size()-1;
    	string ans;
    	while(i>=0){
    		
    		//number is starting to fetch
    		if(s[i]!='+' && s[i]!='-' && s[i]!='/' && s[i]!='*'){
    			int end=i, start;
    			while(s[i]!='+' && s[i]!='-' && s[i]!='/' && s[i]!='*'){
    				start = i;
					if(--i  ==  -1)
						break;
    					
				}
				ans += s.substr(start, (end-start+1));
				if(i<0)
					return ans;
			}
			
			ans += s[i--];
		}
		
		return ans;
    }
};
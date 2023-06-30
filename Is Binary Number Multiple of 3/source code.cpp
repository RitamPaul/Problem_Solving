class Solution{
public:
	int isDivisible(string s){
	    //complete the function here
	    int ind=1, cod=0, cev=0;
	    for(int i=s.size()-1; i>=0; i--, ind++){
	        if(s[i]=='1' && (ind%2 != 0))
	            ++cod;
	        else if(s[i]=='1' && (ind%2 == 0))
	            ++cev;
	    }
	    return abs(cod-cev)%3 == 0 ? true : false ;
	}
};
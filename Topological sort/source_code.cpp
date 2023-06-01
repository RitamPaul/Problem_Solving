class Solution
{
	public:
	unordered_map<int, vector<int>> mp;
	unordered_map<int, bool> mila;
	vector<int> s;
	
	void func(int t){
	    //base-case no parent found
	    if(mp[t].empty()==true){
	        if(mila[t]==false){
	            s.push_back(t);
	            mila[t]=true;
	        }
	        return;
	    }
	    
	    //recursive-program
	    while(mp[t].empty()==false){
	        int p = mp[t].back();
	        mp[t].pop_back();
	        func(p);
	    }
	    if(mila[t]==false){
	        s.push_back(t);
	        mila[t]=true;
	    }
	    return;
	}
	
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    for(auto i=0; i<V; i++){
	        if(adj[i].size()!=0){
	            for(auto ind:adj[i]){
	                mp[ind].push_back(i);
	            }
	        }
	    }
	    
	    for(auto i=0; i<V; i++){
	        func(i);
	    }	    
	    
	    return s;
	}
};

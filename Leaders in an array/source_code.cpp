class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int arr[], int n){
        vector<int> s;
        for(int i=0; i<n; i++){
            if(s.empty())
                s.push_back(arr[i]);
            else{
                while(s.size() and s.back() < arr[i])
                    s.pop_back();
                s.push_back(arr[i]);
            }
        }
        if(s.back() != arr[n-1])
            s.push_back(arr[n-1]);
        return s;
    }
};
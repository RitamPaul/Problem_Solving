class Solution {
  public:
    int distributeTicket(int n, int k) {
        // code here
        if(n==k)    return n;
        int start=0, end=n+1;
        bool flag=false;
        while(true){
            //for first k people:-
            for(int i=1; i<=k; i++){
                ++start;
                if(start == end-1){
                    return start;
                }
            }
            
            //for last k people
            for(int i=1; i<=k; i++){
                --end;
                if(end == start+1){
                    return end;
                }
            }
        }
    }
};
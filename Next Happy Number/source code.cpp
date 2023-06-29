unordered_map<int,int> happy;

class Solution{
public:
    bool func(int N){
        //N is already happy
        if(happy[N]==1){
            happy[N] = 1;
            return true;
        }
        //N is already calculated to be repeating & unhappy
        if(happy[N]==-1)
            return false;
        
        //calculations
        int sum=0, curn = N;
        while(N){
            int rem = N % 10;
            sum += (rem * rem);
            N = N / 10;
        }
        if(sum==1){
            happy[curn] = 1;
            return true;
        }
        happy[curn] = -1;
        N = sum;
        //backtracking + recursion
        return (func(N)==true) ? (happy[curn]=1 && true) : false ;
    }
    
    int nextHappy(int N){
        while(++N){
            if(func(N))     return N;
        }
    }
};
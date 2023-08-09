bool isprime(int num){
    return (num==2 || num==3) ? true : (
        (num%2==0 || num%3==0 || num<=1) ? false :({
            bool ans=true;
            for(int i=5; i<=sqrt(num)+1; i++){
                if(num%i==0){   ans=false;  break;  }
            }
            (ans==true) ? true : false;
        })
    );
}

class Solution{
public: 
    long long int largestPrimeFactor(int N){
        if(isprime(N))  return N;
        int ans=INT_MIN;
        for(int item=2; item<=sqrt(N)+1; item++){
            if(N%item==0){
                if(isprime(item)){
                    ans=max(ans, item);
                    //cout<<item<<",";
                }
                if(isprime(N/item)){
                    ans = max(ans, N/item);
                    //cout<<(N/item)<<",";
                }
            }
        }
        return ans;
    }
};
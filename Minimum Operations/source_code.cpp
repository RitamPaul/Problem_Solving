class Solution
{
  public:
    int minOperation(int n)
    {
        //code here.
        // base case
        if(n == 0)      return 0;
        
        if(n & 1){
            return 1 + minOperation(n-1);
        }
        else{
            return 1 + minOperation(n / 2);
        }
    }
};
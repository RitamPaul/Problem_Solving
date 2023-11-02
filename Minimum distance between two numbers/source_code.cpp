class Solution{
  public:
    int minDist(int a[], int n, int x, int y) {
        // code here
        int xind = INT_MAX, yind = INT_MAX;
        int mindis = INT_MAX;
        for(int i = 0; i < n; ++i){
            if(a[i] == x)       xind = i;
            else if(a[i] == y)  yind = i;
            
            if(xind != INT_MAX and yind != INT_MAX)
                mindis = min(mindis, abs(xind - yind));
        }
        
        if(mindis != INT_MAX)   return mindis;
        return -1;
    }
};
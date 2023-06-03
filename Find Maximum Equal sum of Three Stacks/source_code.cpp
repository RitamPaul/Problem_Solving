class Solution{
public:
    int maxEqualSum(int N1,int N2,int N3,vector<int> &S1,vector<int> &S2,vector<int> &S3){
        int ans=INT_MIN;
        int i=0, j=0, k=0, sum1=0, sum2=0, sum3=0;
        while(i<N1 || j<N2 || k<N3){
            if(i<N1)    sum1+=S1[i];
            if(j<N2)    sum2+=S2[j];
            if(k<N3)    sum3+=S3[k];
            i++;    j++;    k++;
        }
        int mini = min(sum1, min(sum2, sum3));
        int x=N1-1, y=N2-1, z=N3-1, sumx=S1[x], sumy=S2[y], sumz=S3[z];
        while(true){
            if(sumx<=mini && sumy<=mini && sumz<=mini){
                int small = min(sumx, min(sumy, sumz));
                if(small==sumx){
                    x--;
                    sumx+=S1[x];
                }
                else if(small==sumy){
                    y--;
                    sumy+=S2[y];
                }
                else if(small==sumz){
                    z--;
                    sumz+=S3[z];
                }
                if(sumx==sumy && sumy==sumz)
                    ans = max(ans, sumx);
            }
            else
                break;
        }
        
        if(ans==INT_MIN)    return 0;
        return ans;
    }
};
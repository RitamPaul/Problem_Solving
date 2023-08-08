bool cmp(long double &num1, long double &num2){
    return num1<num2;
}
class Solution
{
    public:
    int lower(long double &item, vector<long double> &temp, int start){
        int low=start, high=temp.size()-1, ans=-1;
        //cout<<"#";
        while(low <= high){
            int mid = low + (high - low) / 2;
            //cout<<"{"<<item<<","<<temp[mid]<<"}";
            if(item+temp[mid] == (long double)1){
                ans = mid;
                high = mid - 1;
            }
            else if(item+temp[mid] < (long double)1)
                low = mid + 1;
            else
                high = mid - 1;
        }
        //cout<<"#"<<ans;
        return ans;
    }
    int higher(long double &item, vector<long double> &temp, int start){
        int low=start, high=temp.size()-1, ans=-1;
        //cout<<"$";
        while(low <= high){
            int mid = low + (high - low) / 2;
            //cout<<"{"<<item<<","<<temp[mid]<<"}";
            if(item+temp[mid] == (long double)1){
                ans = mid;
                low = mid + 1;
            }
            else if(item+temp[mid] < (long double)1)
                low = mid + 1;
            else
                high = mid - 1;
        }
        //cout<<"$"<<ans;
        return ans;
    }
    int countFractions(int n, int num[], int den[]){
        vector<long double> temp(n);
        for(auto i=0; i<n; i++)
            temp[i] = (long double)num[i] / den[i];
        sort(temp.begin(), temp.end(), cmp);
        int count=0;
        for(auto i=0; i<n-1; i++){
            //cout<<"("<<temp[i];
            int start = lower(temp[i], temp, i+1), end=-1;
            if(start > 1){
                end = higher(temp[i], temp, start);
                //cout<<"-"<<start<<","<<end;
                count += (end - start + 1);
            }
            //cout<<")";
        }
        return count;
    }
};
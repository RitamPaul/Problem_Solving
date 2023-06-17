//Using single storage(queue)
class Solution
{
    public:
        void Rearrange(int arr[], int n){
            if(n==1)    return;
            queue<long long int> q;
            for(auto i=0; i<n; i++){
                if(arr[i]<0)
                    q.push(arr[i]);
            }
            int i=0;
            while(q.empty()==false){
                long long int front = q.front();
                q.pop();
                if(arr[i]>=0)
                    q.push(arr[i]);
                arr[i] = front;
                i++;
            }
            return;
        }
};
//using separate storage for –ve & +ve integers
class Solution
{
    public:
        void Rearrange(int arr[], int n){
            if(n==1)    return;
            vector<int> pos, neg;
            for(auto i=0; i<n; i++){
                if(arr[i]>=0)    pos.push_back(arr[i]);
                else            neg.push_back(arr[i]);
            }
            int i=0;
            for(auto item:neg){
                arr[i] = item;
                i++;
            }
            for(auto item:pos){
                arr[i] = item;
                i++;
            }
            return;
        }
};

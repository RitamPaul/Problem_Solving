class my{
public:
    int first;
    int second;
    double f;
    my(int a, int b, double c){
        this->first  = a;
        this->second = b;
        this->f      = c;
    }
};
class mycmp{
public:
    bool operator()(my &p1, my &p2){
        double f1 = p1.f;
        double f2 = p2.f;
        if(f1 == f2)
            return (p1.first > p2.first);
        return (f1 > f2);
    }
};
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size(), x, y;
        priority_queue<my, vector<my>, mycmp> pq;
        for(int i=0; i<n-1; ++i)
            pq.push(my(i, n-1, (double)arr[i]/arr[n-1]));
        
        while(pq.size()){
            x = pq.top().first;
            y = pq.top().second;
            pq.pop();
            --k;
            if(k == 0)      break;
            if(y-1 >= 0)
                pq.push(my(x, y-1, (double)arr[x]/arr[y-1]));
        }
        return {arr[x], arr[y]};
    }
};
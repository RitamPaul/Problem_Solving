class Solution{
    public:
    // Function to insert element into the queue
    void insert(queue<int> &q, int k){
        // Your code here
        q.push(k);
        return;
    }
    
    // Function to find frequency of an element
    // return the frequency of k
    int findFrequency(queue<int> &q, int k){
        // Your code here
        int n = q.size(), count = 0;
        while(n--){
            int front = q.front();
            q.pop();
            q.push(front);
            if(front==k)
                ++count;
        }
        return count;
    }
};
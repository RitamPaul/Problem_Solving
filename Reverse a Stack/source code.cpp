class Solution{
public:
    queue<int> q;
    void Reverse(stack<int> &St){
        if(St.empty())   return;
        q.push(St.top());
        St.pop();
        Reverse(St);
        St.push(q.front());
        q.pop();
        return;
    }
};
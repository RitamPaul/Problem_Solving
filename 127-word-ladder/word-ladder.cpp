class Solution {
public:
    string source, target;
    int bfs(string &source, unordered_set<string> &st){
        unordered_set<string> taken;
        queue<string> q;
        q.push(source);
        taken.insert(source);
        int len=0;
        bool ansFound=false;
        while(q.size()){
            int count=q.size();
            ++len;
            while(count--){
                string front=q.front();
                q.pop();
                if(front==target){
                    ansFound=true;
                    break;
                }
                for(int pos=0; pos<front.size(); ++pos){
                    char curChar=front[pos];
                    for(int k=0; k<26; ++k){
                        // new string with 1 char differ
                        front[pos]='a'+k;
                        if(st.count(front) and !taken.count(front)){
                            q.push(front);
                            taken.insert(front);
                        }
                        // backtracking
                        front[pos]=curChar;
                    }
                }
            }
            if(ansFound)
                break;
        }
        if(ansFound==true)
            return len;
        return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=wordList.size();
        this->source = beginWord;
        this->target = endWord;
        unordered_set<string> st;
        st.insert(source);
        for(auto &s : wordList)
            st.insert(s);
        if(!st.count(target))
            return 0;
        return bfs(source, st);
    }
};
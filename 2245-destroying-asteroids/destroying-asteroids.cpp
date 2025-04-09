class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& ast) {
        int n=ast.size();
        unsigned long long sum=mass;
        sort(ast.begin(), ast.end());
        for(auto &i : ast){
            if(sum < i)
                return false;
            sum += (unsigned long long)i;
        }
        return true;
    }
};
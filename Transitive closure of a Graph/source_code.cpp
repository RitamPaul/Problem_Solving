// Back-end complete function Template for C++

class Solution{
public:
    vector<vector<int>> transitiveClosure(int N, vector<vector<int>> graph)
    {
        // code here
        for(int k = 0; k<N; ++k){
            for(int i = 0; i<N; ++i){
                for(int j = 0; j<N; ++j){
                    if(i == j)
                        graph[i][j] = 1;
                    graph[i][j] = graph[i][j] or (graph[i][k] and graph[k][j]);
                }
            }
        }
        return graph;
    }
};
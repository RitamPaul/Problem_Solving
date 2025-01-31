//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int n;
    bool possible(vector<vector<int>> &mat, int row, int col, int val){
        // checking entire row
        for(int j=0; j<n; ++j){
            if(mat[row][j]==val)
                return false;
        }
        // checking entire col
        for(int i=0; i<n; ++i){
            if(mat[i][col]==val)
                return false;
        }
        // checking small 3x3 grid
        int gridrow=(row/3), gridcol=(col/3);
        for(int i=(3*gridrow); i<(3*(gridrow+1)); ++i){
            for(int j=(3*gridcol); j<(3*(gridcol+1)); ++j){
                if(mat[i][j]==val)
                    return false;
            }
        }
        return true;
    }
    bool f(vector<vector<int>> &mat){
        // traversing all cells
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                // empty cell found
                if(mat[i][j]==0){
                    // traverse all possible values
                    for(int k=1; k<=9; ++k){
                        // place the safe value & move to place another value
                        if(possible(mat, i, j, k)){
                            mat[i][j]=k;
                            bool furtherpossible=f(mat);
                            if(furtherpossible)
                                return true;
                            mat[i][j]=0;
                        }
                    }
                    // traversed all but none fits
                        return false;
                }
            }
        }
        return true;
    }
    // Function to find a solved Sudoku.
    void solveSudoku(vector<vector<int>> &mat) {
        // code here
        n=mat.size();
        f(mat);
        return;
    }
};

//{ Driver Code Starts.

vector<int> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    int num;
    vector<int> res;
    while (ss >> num) {
        res.push_back(num);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<vector<int>> grid;
        for (int i = 0; i < 9; i++) {
            vector<int> v = inputLine();
            grid.push_back(v);
        }

        Solution ob;

        ob.solveSudoku(grid);

        for (auto v : grid) {
            for (auto elem : v) {
                cout << elem << " ";
            }
            cout << endl;
        }

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
class Solution 
{
    public:
    bool put(int grid[N][N], int row, int col, int choice){
        for(auto i=0; i<N; i++){
            //row check
            if(grid[row][i] == choice)
                return false;
            
            //column check
            if(grid[i][col] == choice)
                return false;
            
            //own square check
            int x = 3*(row/3) + i/3;
            int y = 3*(col/3) + i%3;
            if(grid[x][y] == choice)
                return false;
        }
        return true;
    }
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N]){
        for(auto row=0; row<N; row++){
            for(auto col=0; col<N; col++){
                //empty cell found
                if(grid[row][col] == 0){
                    //choose 1 to 9 for that empty cell
                    for(auto choice=1; choice<=N; choice++){
                        //place the choice if it is valid
                        if(put(grid, row, col, choice) == true){
                            grid[row][col] = choice;
                            //recursive call to solve rest empty cell
                            if(SolveSudoku(grid) == true)
                                return true;
                            //backtrack
                            grid[row][col] = 0;
                        }
                    }
                    //already choosen 1 to 9 but no-one fits
                    return false;
                }
            }
        }
        return true;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]){
        for(auto i=0; i<N; i++){
            for(auto j=0; j<N; j++)
                cout << grid[i][j] << " ";
        }
        return;
    }
};
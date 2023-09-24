class Solution {
public:
    double champagneTower(int pour, int row, int glass) {
      if(row == 0 and glass == 0){
        if(pour > 1)      return 1;
        else              return pour;
      }
      
      vector<vector<double>> grid(100, vector<double>(100, 0));
      grid[0][0] = pour;
      double leftextra, rightextra;
      for(int i = 1; i<=row; ++i){
        for(int j=0; j<=i; ++j){
          leftextra = rightextra = 0;
          if(i-1 >= 0 and j-1 >= 0 and grid[i-1][j-1] > 1)
            leftextra = (grid[i-1][j-1] - 1) / (double)2;
          if(i-1 >= 0 and grid[i-1][j] > 1)
            rightextra = (grid[i-1][j] - 1) / (double)2;
          grid[i][j] = leftextra + rightextra;
          
          //current grid containing answer
          if(i == row and j == glass){
            if(grid[i][j] > 1)    return 1;
            else                  return grid[i][j];
          }
        }
      }
      return 0;
    }
};
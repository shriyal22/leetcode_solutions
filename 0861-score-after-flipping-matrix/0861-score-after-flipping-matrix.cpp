class Solution {
public:
    bool flipIt(vector<vector<int>>& grid, int c, int m){
        int count = 0;
        for(int i=0;i<m;i++){
            if(grid[i][c] == 0) count++;
        }
        return count > (m-count);
    }
    void flipCol(vector<vector<int>>& grid, int c, int m){
        for(int i=0;i<m;i++){
            if(grid[i][c] == 0) grid[i][c] = 1;
            else grid[i][c] = 0;
        }
    }
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for(int i=0;i<m;i++){
            if(grid[i][0] == 0){
                grid[i][0] = 1;
                for(int j=1;j<n;j++){
                    if(grid[i][j] == 0) grid[i][j] = 1;
                    else grid[i][j] = 0;
                }
            }
        }
        for(int j=1;j<n;j++){
            if(flipIt(grid, j, m)){
                flipCol(grid, j, m);
            }
        }

        int score = 0;
        int multiply = 1;
        for(int j=n-1;j>=0;j--){
            for(int i=0;i<m;i++){
                if(grid[i][j]) score += multiply*grid[i][j];
            }
            multiply = multiply*2;
        }
        return score;
    }
};
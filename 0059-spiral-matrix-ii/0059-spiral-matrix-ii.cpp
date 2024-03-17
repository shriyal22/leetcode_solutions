class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n, 0));
        
        int val = 1;
        int left = 0, right = n-1, up = 0, down = n-1;
        
        while(left<=right && up<=down){
            for(int k=left;k<=right;k++){
                mat[up][k] = val;
                val++;
            }
            up++;
            for(int k=up;k<=down;k++){
                mat[k][right] = val;
                val++;
            }
            right--;
            if(up<=down){
                for(int k=right;k>=left;k--){
                    mat[down][k] = val;
                    val++;
                }
                down--;
            }
            if(left<=right){
                for(int k=down;k>=up;k--){
                    mat[k][left] = val;
                    val++;
                }
                left++;
            }
        }
        return mat;
    }
};
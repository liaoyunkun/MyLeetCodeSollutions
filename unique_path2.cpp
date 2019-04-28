class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        long* ans[n];
        for(auto i=0;i<n;i++){
            ans[i] = new long[m];
        }
        ans[0][0] = obstacleGrid[0][0]==0? 1 : 0;
        for(auto i=1;i<n;i++){
            ans[i][0] = (1-obstacleGrid[i][0])*(1-obstacleGrid[i-1][0])*ans[i-1][0];
        }
        
        for(auto i=1;i<m;i++){
            ans[0][i] = (1-obstacleGrid[0][i])*(1-obstacleGrid[0][i-1])*ans[0][i-1];
        }
        
        for(auto i=1;i<n;i++){
            for(auto j=1;j<m;j++){
                ans[i][j] = (1-obstacleGrid[i][j])*(ans[i][j-1]*(1-obstacleGrid[i][j-1])+ans[i-1][j]*(1-obstacleGrid[i-1][j]));
            }
        }
        
        long result = ans[n-1][m-1];
        for(auto i=0;i<n;i++){
            delete [] ans[i];
        }
        return result;
    }
};
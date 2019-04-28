class Solution {
public:
    int uniquePaths(int m, int n) {
        //Bottom-Up approach
        int* ans[n];
        for(auto i=0;i<n;i++){
            ans[i] = new int[m];
        }
        for(auto i=0;i<n;i++){
            ans[i][0] = 1;
        }
        for(auto i=0;i<m;i++){
            ans[0][i] = 1;
        }
        for(auto i=1;i<n;i++){
            for(auto j=1;j<m;j++){
                ans[i][j] = ans[i][j-1]+ans[i-1][j];
            }
        }
        int result = ans[n-1][m-1];
        for(auto i=0;i<n;i++){
            delete [] ans[i];
        }
        return result;
    }
};
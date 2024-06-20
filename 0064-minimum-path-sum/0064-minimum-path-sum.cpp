class Solution {
public:
    int dp[200][200];
    
    int solve(int i,int j,vector<vector<int>>& grid,int m,int n)
    {
      if(i == m-1 && j==n-1)
          return grid[i][j];
        
      if( i>=m || j>=n)
          return 1e8;
        if(dp[i][j] != -1)
            return dp[i][j];
        int right=grid[i][j] + solve(i,j+1,grid,m,n);
        int down=grid[i][j] +solve(i+1,j,grid,m,n);
        
        return dp[i][j]=min(right,down);
    
    }
    
    
    int minPathSum(vector<vector<int>>& grid) {
        
        memset(dp,-1,sizeof(dp));
          int m=grid.size();
        int n=grid[0].size();
        return solve(0,0,grid,m,n);
        
    }
};
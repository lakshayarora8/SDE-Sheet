class Solution {
public:
    
    int dp[200][200];
    int solve(int i,int j,int m,int n,vector<vector<int>>& triangle)
    {
        if(i == m-1)
            return triangle[i][j];
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int down= triangle[i][j] + solve(i+1,j,m,n,triangle);
        int downright=triangle[i][j] +solve(i+1,j+1,m,n,triangle);
        
        return dp[i][j]= min(down,downright);
        
    }
    
    
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int m=triangle.size();
        int n=triangle[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,m,n,triangle);
    }
};
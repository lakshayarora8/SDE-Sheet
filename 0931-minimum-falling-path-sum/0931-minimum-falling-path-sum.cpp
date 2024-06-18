class Solution {
public:
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int m=matrix.size();
        int n=matrix[0].size();
        
        vector<vector<int>> dp(m,vector<int> (n,-1));
        for(int i=0;i<n;i++)
        {
          dp[0][i]=matrix[0][i];
        }
        for(int i=1;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int up= matrix[i][j] + dp[i-1][j];
                int left=matrix[i][j];
                if(j-1>=0) left+= dp[i-1][j-1];
                else left+=1e8;
                int right=matrix[i][j];
                if(j+1<n) right+= dp[i-1][j+1];
                else right+=1e8;
                dp[i][j]=min(up,min(left,right));
            }
        }
        int ans=dp[m-1][0];

        for(int i=0;i<n;i++)
        {
            ans=min(ans,dp[m-1][i]);
        }
        return ans;
    }
};
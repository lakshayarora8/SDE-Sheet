class Solution {
public:
    // int solve(int i,int j,string &s,string &t)
    // {
    //     if(j<0)
    //     return 1;
    //     if(i<0)
    //     return 0;
    //     if(dp[i][j] != -1)
    //     return dp[i][j];

    //     int notpick=solve(i-1,j,s,t);
    //     int pick=0;
    //     if(s[i] == t[j])
    //     pick=solve(i-1,j-1,s,t);
    //     return dp[i][j]=pick+notpick;
    // }


    int numDistinct(string s, string t) {
        
        int m=s.size();
        int n=t.size();
        vector<vector<double>> dp(m+1,vector<double>(n+1,0));
        for(int i=0;i<=m;i++) dp[i][0]=1;

        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1] == t[j-1])
                {
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
                }
                else
                dp[i][j]=dp[i-1][j];
            }
        }
        return (int)dp[m][n];
    }
};
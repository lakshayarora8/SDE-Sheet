class Solution {
public:
    int dp[1000][1000];
    int solve(int i,int j,string &s,string &t)
    {
        if(j<0)
        return 1;
        if(i<0)
        return 0;
        if(dp[i][j] != -1)
        return dp[i][j];

        int notpick=solve(i-1,j,s,t);
        int pick=0;
        if(s[i] == t[j])
        pick=solve(i-1,j-1,s,t);
        return dp[i][j]=pick+notpick;
    }


    int numDistinct(string s, string t) {
        
        int m=s.size();
        int n=t.size();
        memset(dp,-1,sizeof(dp));
        return solve(m-1,n-1,s,t);

        
    }
};
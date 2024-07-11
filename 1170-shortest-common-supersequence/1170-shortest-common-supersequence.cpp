class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {

        int m=s.size();
        int n=t.size();
        vector<vector<int>> dp(m+1,vector<int> (n+1,0));
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1] == t[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        string lcs = "";
        int i = m, j = n;
        while (i > 0 && j > 0) {
            if (s[i - 1] == t[j - 1]) {
                lcs += s[i - 1];
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }

        reverse(lcs.begin(), lcs.end());
        i=0,j=0;
        int k=0;
        string ans="";
        int lcs_size=lcs.size();
        while(i<m && j<n && k<lcs_size)
        {   
            while(s[i] != lcs[k])
            {
                ans+=s[i++];
            }
             while(t[j] != lcs[k])
            {
                ans+=t[j++];
            }
            i++;
            j++;
            ans+=lcs[k++];
        }
        while(i<m)
        ans+=s[i++];
        while(j<n)
        ans+=t[j++];
        return ans;
    }
};
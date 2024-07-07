class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<pair<int,int>>> v(m,vector<pair<int,int>>(n,{0,0}));
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 'X')
                {
                    v[i][j].first=1;
                    v[i][j].second=1;
                }
                else if(grid[i][j] == 'Y')
                v[i][j].first=-1;
            }
        }
        for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {

            int top = (i > 0) ? v[i - 1][j].first : 0;
            int left = (j > 0) ? v[i][j - 1].first : 0;
            int topLeft = (i > 0 && j > 0) ? v[i - 1][j - 1].first : 0;

            if(v[i][j].second != 1)
            {
            int x1 = (i > 0) ? v[i - 1][j].second : 0;
            int x2 = (j > 0) ? v[i][j - 1].second : 0;
            int x3 = (i > 0 && j > 0) ? v[i - 1][j - 1].second : 0;
            v[i][j].second= x1 | x2 |x3;
            }
            v[i][j].first += top + left - topLeft;

            if(v[i][j].first == 0 && v[i][j].second)
            ans++;
        }
        }
        return ans;
        
    }
};
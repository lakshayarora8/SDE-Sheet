class Solution {
public:

      int orangesRotting(vector<vector<int>>& grid) {
        
        int count=-1,fresh=0;
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>> q;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i,j});
                    grid[i][j]=-1;
                }
                else if(grid[i][j] == 1)
                fresh++;
            }
        }
        if(fresh == 0)
        return 0;

        int index1[]={-1,0,1,0};
        int index2[]={0,-1,0,1};
        while(!q.empty())
        {
            int size=q.size();
            count++;
            for(int s=0;s<size;s++)
            {
                  int oldi=q.front().first;
                  int oldj=q.front().second;
                  q.pop();
                for(int ind=0;ind<4;ind++)
                {
                    int newi=oldi + index1[ind];
                    int newj=oldj + index2[ind];

                    if(newi >=0 && newi<m && newj>=0 && newj<n && grid[newi][newj]==1)
                    {
                        q.push({newi,newj});
                        grid[newi][newj]=-1;
                    }
                }
            }
        }

        for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        if(grid[i][j]==1)
        return -1;
        return count;
    }
};
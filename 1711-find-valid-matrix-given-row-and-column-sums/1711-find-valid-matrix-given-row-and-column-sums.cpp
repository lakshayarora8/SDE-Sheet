class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& row, vector<int>& col) {
        
        int m=row.size(),n=col.size();
        vector<vector<int>> ans(m,vector<int> (n,0));
        int sum=0;
        for(auto it:row)sum+=it;

    int x,y;
    while(sum !=0){
        int xmin=INT_MAX;
        for(int i=0;i<m;i++)
        {
            if(row[i] != 0 && row[i]<xmin)
            {
                x=i;
                xmin=row[i];
            }
        }
        int ymin=INT_MAX;
        for(int j=0;j<n;j++)
        {
             if(col[j] != 0 && col[j]<ymin)
            {
                y=j;
                ymin=col[j];
            }
        }
        int mini=min(xmin,ymin);
        row[x]-=mini;
        col[y]-=mini;
        sum-=mini;
        ans[x][y]=mini;
    }

        
    return ans;

    }
};
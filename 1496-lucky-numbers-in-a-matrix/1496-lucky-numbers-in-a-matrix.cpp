class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> row(m),col(n);
        vector<int> ans;
        for(int i=0;i<m;i++)
        {
            row[i]=matrix[i][0];
            for(int j=0;j<n;j++)
            {
                row[i]=min(row[i],matrix[i][j]);
            }
        }
         for(int i=0;i<n;i++)
        {
            col[i]=matrix[0][i];
            for(int j=0;j<m;j++)
            {
                col[i]=max(col[i],matrix[j][i]);
            }
        }
        for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        if(matrix[i][j] == row[i] && matrix[i][j]==col[j])
        ans.push_back(matrix[i][j]);
        
        return ans;
        
    }
};
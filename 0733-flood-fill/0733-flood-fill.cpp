class Solution {
public:
    void dfs(int i, int j,vector<vector<int>>& grid, int color,int srcolor)
    {
        int m=grid.size(),n=grid[0].size();
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]!=srcolor)
        return; 

        grid[i][j]=color;

        dfs(i+1,j,grid,color,srcolor);
        dfs(i,j+1,grid,color,srcolor);
        dfs(i-1,j,grid,color,srcolor);
        dfs(i,j-1,grid,color,srcolor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int srcolor=image[sr][sc];
        if (srcolor == color) return image; 
        dfs(sr,sc,image,color,srcolor);
        return image;
    }
};
class Solution {
public:
    bool ans=true;
    void dfs(int u,vector<int>& color,vector<vector<int>>& graph,int currcolor)
    {
        color[u]=currcolor;

        for(auto v: graph[u])
        {
            if(color[v] == currcolor)
            ans= false;
            if(color[v] == -1)
            dfs(v,color,graph,1-currcolor);
        }

    }

    bool isBipartite(vector<vector<int>>& graph) {

        int n=graph.size();
        vector<int> color(n,-1);

        for(int i=0;i<n;i++)
        {
            if(color[i] == -1 )
            {
                dfs(i,color,graph,0);
            }
        }
        return ans;
    }
};
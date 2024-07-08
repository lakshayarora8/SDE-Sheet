class Solution {
public:
    bool ans=true;
    void dfs(int u,vector<int> adj[],vector<int> &vis,vector<int> &pathvis)
    {
        vis[u]=1;
        pathvis[u]=1;
        for(auto v: adj[u])
        {
           if(vis[v] && pathvis[v])
           {
            ans=false;
           }
           else if(!vis[v])
           dfs(v,adj,vis,pathvis);
        }
        pathvis[u]=0;

    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> adj[numCourses];
        vector<int> vis(numCourses,0);
        for(auto it: prerequisites)
        adj[it[1]].push_back(it[0]);
        vector<int> pathvis(numCourses,0);
        for(int i=0;i<numCourses;i++)
        if(!vis[i] )
        dfs(i,adj,vis,pathvis);
       
        return ans;

        
    }
};
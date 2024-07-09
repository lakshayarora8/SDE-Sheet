class Solution {
public:

    bool bfs(int u,vector<int>& color,vector<vector<int>>& graph,int currcolor)
    {
        queue<pair<int,int>> q;
        q.push({u,currcolor});

        while(!q.empty())
        {
            int node=q.front().first;
            int curr=q.front().second;
            q.pop();
            for(auto v: graph[node])
            {
                if(color[v] == curr)
                {
                    return false;
                }
                else if(color[v] == -1)
                {
                    q.push({v,1-curr});
                    color[v]=1-curr;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {

        int n=graph.size();
        vector<int> color(n,-1);

        for(int i=0;i<n;i++)
        {
            if(color[i] == -1 &&  bfs(i,color,graph,0)==false )
            {
               return false;
            }
        }
        return true;
    }
};
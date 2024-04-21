//via dfs
bool checkdfs(int x,vector<int> adj[],vector<int>&visited ,int parent)
    {
        visited[x] = 1;
        for(auto i: adj[x])
        {
            if(!visited[i])
            {
                if(checkdfs(i, adj, visited, x))return true;
            }
            else if(i !=parent)
            return true;
        }
        return false;
    }
    bool isCycle(int v, vector<int> adj[]) {
        // Code here
        vector<int>visited(v,0);
        for(int i = 0;i<v;i++)
        {
            if(!visited[i])
            if(checkdfs(i, adj, visited, -1)) return true;
        }
        return false;
    }

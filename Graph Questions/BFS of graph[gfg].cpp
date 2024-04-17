void bfs(vector<int> adj[],vector<int>&ans,unordered_map<int,bool> &visited, int node )
    {
        queue<int>q;
        q.push(node);
        visited[node] = true;
        while(!q.empty())
        {
            int f = q.front();
            q.pop();
            ans.push_back(f);
            for(auto i: adj[f])
            {
                if(!visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int>ans;
        //queue<int>q;
        unordered_map<int,bool>visited;
        bfs(adj, ans,visited,0);
        return ans;
    }

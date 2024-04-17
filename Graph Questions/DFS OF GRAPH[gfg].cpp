void dfs(vector<int> adj[],unordered_map<int,bool>&visited,vector<int>&ans,int node)
   {
       ans.push_back(node);
       visited[node] = 1;
       for(auto i: adj[node])
       {
           if(!visited[i])
           {
              // visited[i] = 1;
               dfs(adj,visited,ans,i);
           }
       }
   }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        unordered_map<int,bool>visited;
        vector<int>ans;
        dfs(adj,visited,ans,0);
        return ans;
    }

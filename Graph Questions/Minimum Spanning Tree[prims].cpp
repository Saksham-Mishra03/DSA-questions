int spanningTree(int v, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>visited(v,0);
        
        pq.push({0,0});
        //visited[0]=1;
        
        int sum = 0;
        
        while(!pq.empty())
        {
            auto f = pq.top();
            pq.pop();
            
            int wt = f.first;
            int node= f.second;
            
            
            if(visited[node])continue;
            
            visited[node] = 1;
            sum += wt;
            
            for(auto i: adj[node])
            {
                int adwt = i[1];
                int adnode = i[0];
                
                if(!visited[adnode])
                pq.push({adwt, adnode});
            }
        }
        return sum;
    }

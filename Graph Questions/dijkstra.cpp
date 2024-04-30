    vector <int> dijkstra(int v, vector<vector<int>> adj[], int s)
    {
        // Code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dis(v,INT_MAX);
        
        pq.push({0,s});
        dis[s] = 0;
        
        while(!pq.empty())
        {
            auto f = pq.top();
            int wt = f.first;
            int node = f.second;
            pq.pop();
            
            for(auto i: adj[node])
            {
                int adnode = i[0];
                int adwt = i[1];
                
                if(wt+adwt< dis[adnode])
                {
                    dis[adnode] = wt+adwt;
                    pq.push({dis[adnode], adnode});
                }
            }
        }
        return dis;
    }

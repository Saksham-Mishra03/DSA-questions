#include<bits/stdc++.h>
using namespace std;
class Edge{
	public:
	int s;
	int d;
	int w;
};
void bfs(vector<vector<pair<int,int>>>&graph,vector<int>&op, int s)
{
	deque<int>dq;
	op[s] = 0; // source se spurce tk ka mini dist =0
	dq.push_front(s);
	while(!dq.empty())
	{
		int f = dq.front();
		dq.pop_front();
		
		//explore all neightbours of f
		for(auto i: graph[f]){
			int d = i.first;
			int w = i.second;
			
			if(op[d]>w+op[f]){
			
				op[d] = w+op[f];
				
				if(w==1) // neghbr node ko last me dalo
				dq.push_back(d);
				else
				dq.push_front(d);
			}
		}
	}
}
int main()
{/*
	int n, e;
    cin >> n >> e;
    Edge *input = new Edge[e]; //edges array
    
    for(int i = 0;i<e;i++)
    {
    	int sr,dr,wr;
    	cin>>sr>>dr>>wr;
    	input->s = sr;
    	input->d = dr;
    	input->w = wr;
	}
	//chlo beta ab edges array se adj list bnao
	
	vector<vector<pair<int,int>>>graph; //vector me phla source hoga and har source k lie pair dalege jisme 1st value desti and 2nd value wt hogi
	for(int i = 0;i<e;i++)
	{
		
		graph[input[i].s].push_back({input[i].d,input[i].w});
		graph[input[i].d].push_back({input[i].s,input[i].w});
	}
	*/
	/*
	for(int i = 0;i<n;i++)
	{
		cout<<graph[i][0].first<<" ";
	}
	*/
	
	int V = 6, E = 7, vertex_source = 0;
    vector<vector<pair<int, int> > > graph(V);
    vector<vector<int> > edges{ { 0, 1, 1 }, { 1, 2, 1 },
                                { 2, 3, 1 }, { 3, 4, 1 },
                                { 4, 5, 0 }, { 5, 0, 0 },
                                { 1, 4, 1 } };
    // Representing the graph as adjacent list
    for (auto edge : edges) {
        graph[edge[0]].push_back({ edge[1], edge[2] });
        graph[edge[1]].push_back({ edge[0], edge[2] });
    }
	
	
	vector<int>op(V,INT_MAX);
	bfs(graph,op,1);
	
	for(int i = 0;i<V;i++)
	cout<<op[i]<<" ";
}

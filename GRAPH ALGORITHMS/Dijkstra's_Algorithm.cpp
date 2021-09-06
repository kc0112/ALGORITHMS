 vector <int> dijkstra(int V, vector<vector<int>> adj[], int s){
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;
        
        pq.push(make_pair(0,s));
        
        vector<int>visited(V,-1);
    
        while(!pq.empty()){
            int node = pq.top().second;
            int wsf = pq.top().first;
            pq.pop();
            
            if(visited[node]!=-1){
                continue;
            }
            visited[node] = wsf;
            
            vector<vector<int>>edges = adj[node];
            
            for(vector<int>edge:edges){
                int nbr = edge[0]; int wt = edge[1];
                
                if(visited[nbr] == -1)
                    pq.push(make_pair(wt+wsf,nbr));
            }
        }
        
        
        return visited;
 }

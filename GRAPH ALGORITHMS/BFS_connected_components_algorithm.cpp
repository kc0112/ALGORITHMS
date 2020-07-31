#include <bits/stdc++.h>
using namespace std;

// Add edge
void addEdge(vector<int> adj[], int s, int d) {
  adj[s].push_back(d);
  adj[d].push_back(s);
}

// Print the graph
void printGraph(vector<int> adj[], int V) {
  for (int d = 0; d < V; ++d) {
    cout << "\n Vertex "
       << d << ":";
    for (auto x : adj[d])
      cout << "-> " << x;
    cout<<endl;
  }
  cout<<endl<<endl;
}

void BFS(vector <int> adj[],int s,int V,int visited[]){

    queue<int>Queue;
    visited[s]=true;
    Queue.push(s);

    while(!Queue.empty())
    {
        int curr_vertex=Queue.front();
        cout<<" VISITED "<<curr_vertex<<" ";
        Queue.pop();

        for (auto x:adj[curr_vertex])
        {
            if(!visited[x])
            {
                visited[x]=true;
                Queue.push(x);
            }
        }
    }
}

void all_nodes(vector<int>adj[],int V){
     int visited[V];
     for(int i{0};i<V;i++)
        visited[i]=false;

     for(int i=0;i<V;i++){
        if(visited[i]==false){
            BFS(adj,i,V,visited);
        }
     }
}

int main() {
  int V = 10;
  // Create a undirected graph
  // an adjacency list of size V with each index having a vertex and each index is a vector
  vector<int> adj[V];

  // Add edges
  addEdge(adj, 0, 2);
  addEdge(adj, 0, 4);
  addEdge(adj, 2, 4);
  addEdge(adj, 4, 6);
  addEdge(adj, 4, 8);
  addEdge(adj, 1, 3);
  addEdge(adj, 5, 7);
  addEdge(adj, 5, 9);
  addEdge(adj, 7, 9);
  printGraph(adj, V);

  all_nodes(adj,V);

}

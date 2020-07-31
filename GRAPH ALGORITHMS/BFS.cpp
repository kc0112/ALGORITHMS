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

void BFS(vector <int> adj[],int s,int V){
    cout<<" BFS TRAVERSAL "<<endl<<endl;
    bool *visited=new bool[V];
    for(int i{0};i<V;i++)
        visited[i]=false;

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

int main() {
  int V = 6;
  // Create a undirected graph
  //an adjacency list of size V with each index having a vertex and each index is a vector
  vector<int> adj[V];

  // Add edges
  addEdge(adj, 0, 1);
  addEdge(adj, 0, 2);
  addEdge(adj, 1, 3);
  addEdge(adj, 2, 3);
  addEdge(adj, 2, 4);
  addEdge(adj, 3, 4);
  addEdge(adj, 3, 5);
  addEdge(adj, 4, 5);
  printGraph(adj, V);

   BFS(adj,0,V);

}

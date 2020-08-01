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

void DFS(vector <int> adj[],int s,int V){
    bool *visited=new bool [V];
    for(int i{0};i<V;i++){
        visited[i]=false;
    }
    stack<int>st;
    st.push(s);

    while(!st.empty()){
        int top=st.top();
        st.pop();
        if(!visited[top]){
        visited[top]=true;
        cout<<top<<" ";
        for (auto x:adj[top])
        {
            if(!visited[x])
            {
               st.push(x);
            }
        }
      }
    }
}

int main() {
  int V = 6;
  // Create a undirected graph
  // an adjacency list of size V with each index having a vertex and each index is a vector
  vector<int> adj[V];

  // Add edges
  addEdge(adj, 0, 2);
  addEdge(adj, 0, 4);
  addEdge(adj, 2, 4);
  addEdge(adj, 4, 1);
  addEdge(adj, 4, 3);
  addEdge(adj, 4, 3);
  addEdge(adj, 2, 5);
  addEdge(adj, 5, 3);
  addEdge(adj, 1, 3);
  DFS(adj,0,V);

}

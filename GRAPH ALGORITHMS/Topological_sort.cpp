#include <iostream>
#include <stack>
#include <list>
using namespace std;

class Graph{
    int V;
     list<int>* adj;
public:
    Graph(int V);
    void addEdge(int v,int u);
    void toposort();
    void toposortUtil(int v,bool visited[],stack<int>&s);
};

Graph::Graph(int V){
    this->V=V;
    adj=new list<int>[V];
}

void Graph::addEdge(int v,int u){
    adj[v].push_back(u);
}

void Graph::toposortUtil(int v,bool visited[],stack<int>&s){
   visited[v]=true;
   list<int>::iterator i;
   for(i=adj[v].begin();i!=adj[v].end();i++){
        if(!visited[*i]){
            toposortUtil(*i,visited,s);
        }
   }
   s.push(v);
}

void Graph::toposort(){
    stack<int>s;
    bool *visited=new bool[V];
    for(int i=0;i<V;i++){
        visited[i]=false;
    }

    for(int i=0;i<V;i++){
            if(!visited[i]){
        toposortUtil(i,visited,s);
     }
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}

int main(){
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.toposort(); 
}

#include <bits/stdc++.h>
using namespace std;

void createEdge(vector<int>adj[],int u,int v){
    adj[u].push_back(v);
}

int find(int parent[],int i){
    if(parent[i]==-1){
        return i;
    }
    return find(parent,parent[i]);
}

void union_(int parent[],int x,int y){
    int xset = find(parent, x);
    int yset = find(parent, y);
    if(xset != yset)
    {
        parent[xset] = yset;
    }
}

int isCycle(vector<int>adj[],int V){
    int *parent =  new int [V];
    memset(parent,-1,V*sizeof(int));
    for(int u{0};u<V;u++){
        for(auto v:adj[u]){
            int x=find(parent,u);
            int y=find(parent,v);
            if(x==y)
                return 1;
            union_(parent,x,y);
        }
    }
    return 0;
}

int main(){
    int V=3;
    vector<int>adj[V];
    createEdge(adj,0,1);
    createEdge(adj,1,2);
    createEdge(adj,0,2);
    if(isCycle(adj,V))
        cout<<"GRAPH CONTAINS CYCLE"<<endl;
    else
        cout<<"GRAPH DOESNT CONTAIN CYCLE"<<endl;
}

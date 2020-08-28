#include<bits/stdc++.h>
using namespace std;

struct Graph{
    int V;
    int E;
    vector<pair<int,pair<int,int>>>edge;
};

Graph* createGraph(int V,int E){
    Graph* graph =new Graph;
    graph->V=V;
    graph->E=E;
    return graph;
}

struct subset{
    int parent;
    int Rank;
};

int Find(subset s[],int i){
    if(s[i].parent!=i)
        s[i].parent=Find(s,s[i].parent);
    return s[i].parent;
}

void Union(subset s[],int x,int y){
    int xroot=Find(s,x);
    int yroot=Find(s,y);

    if(s[xroot].Rank>s[yroot].Rank){
        s[yroot].parent=xroot;
    }
    else if(s[xroot].Rank<s[yroot].Rank){
        s[xroot].parent=yroot;
    }
    else{
        s[xroot].parent=yroot;
        s[yroot].Rank++;
    }
}

void KruskalMST(priority_queue< pair<int,pair<int,int>>, vector <pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>>pq,int V,int E){
     // Allocate memory for creating V ssubsets
    subset *s = new subset[( V * sizeof(subset) )];
    vector<pair<int,pair<int,int>>>result(V);
    // Create V subsets with single elements
    for (int v = 0; v < V; ++v)
    {
        s[v].parent = v;
        s[v].Rank = 0;
    }

    int i=0,e=0;
    while(e<V-1&&i<E){
        int x=Find(s,pq.top().second.first);
        int y=Find(s,pq.top().second.second);

        if(x!=y){
            result[e++]=pq.top();
            Union(s,x,y);
        }
        pq.pop();
    }
    cout<<"Following are the edges in the constructed MST\n";
    for (i = 0; i < e; ++i)
        cout<<result[i].second.first<<" -- "<<result[i].second.second<<" == "<<result[i].first<<endl;
    return;
}

int main(){
    int V = 4; // Number of vertices in graph
    int E = 5; // Number of edges in graph
    // add edge 0-1
    priority_queue< pair<int,pair<int,int>>, vector <pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>>pq;
    pq.push(make_pair(10,make_pair(0,1)));
    pq.push(make_pair(6,make_pair(0,2)));
    pq.push(make_pair(5,make_pair(0,3)));
    pq.push(make_pair(15,make_pair(1,3)));
    pq.push(make_pair(4,make_pair(2,3)));

    KruskalMST(pq,V,E);
    return 0;
}

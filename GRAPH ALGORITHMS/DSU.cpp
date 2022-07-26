 class UnionFind{
    public:
    vector<int> parent;
    vector<int> rank;

    UnionFind(int v){
        for(int i=0; i<v; i++){
            parent.push_back(i);
            rank.push_back(0);
        }
    }

    void union_(int v1, int v2){
        int pv1 = find_(v1);
        int pv2 = find_(v2);

        if (pv1 != pv2){
            int rankv1 = rank[pv1];
            int rankv2 = rank[pv2];

            if(rankv1 < rankv2)
                parent[pv1] = pv2;
            else if(rankv1 > rankv2)
                parent[pv2] = pv1;
            else{
                parent[pv2] = pv1;
                rank[pv1]++;
            }
        }
    }

    int find_(int v){
        if (parent[v] == v){
            return v;
        }

        return parent[v] = find_(parent[v]);
    }
      
      bool isCycle(int u,int v){
          return find_(u) == find_(v);
      }
 };

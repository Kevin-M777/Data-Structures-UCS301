#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u,v,w;
};
//creating the disjoint set structure
struct DSU {
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n);
        rank.assign(n,0);
        for (int i=0;i<n;i++) parent[i]=i;
    }
    int find(int x) {
        if (parent[x]!=x) parent[x]=find(parent[x]);
        return parent[x];
    }
    void unify(int x,int y) {
        x=find(x); y=find(y);
        if (x==y) return;
        if (rank[x]<rank[y]) parent[x]=y;
        else if (rank[x]>rank[y]) parent[y]=x;
        else { parent[y]=x; rank[x]++; }
    }
};
bool compare(Edge a,Edge b){return a.w<b.w;} //comparison function made to be used in sorting

void kruskals(vector<Edge>& edges,int n) {
    sort(edges.begin(), edges.end(),compare);
    DSU dsu(n);
    cout << "Edge  Weight\n";
    for (auto &e : edges) {
        int u=e.u, v=e.v, w=e.w;
        if (dsu.find(u) != dsu.find(v)) {
            cout << u <<" "<< v <<" "<<w<<"\n";
            dsu.unify(u, v);
        }
    }
}

int main() {
    int n=5;
    vector<Edge> edges={{0,1,2},{0,3,6},{1,2,3},{1,3,8},{1,4,5},{2,4,7}};
    kruskals(edges,n);

    return 0;
}

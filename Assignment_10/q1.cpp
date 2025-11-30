#include <iostream>
#include <vector>
using namespace std;

class Graph {
public:
    int n;
    vector<vector<int>> adj;
    Graph(int n){this->n=n;adj.resize(n);}
    void addEdge(int u,int v) {
        adj[u].push_back(v); // directed graph
    }
    int outDegree(int u) {
        return adj[u].size();
    }
    int inDegree(int u) {
        int count=0;
        for (int i=0;i<n;i++){for (int v: adj[i]){if(v==u)count++;}}  
        return count;
    }
    void adjacentVertices(int u) {
        cout<<u<<": ";
        for (int v: adj[u]) cout<<v<<" ";
        cout<<"\n";
    }
    int numberOfEdges() {
        int count=0;
        for (int i=0;i<n;i++){count += adj[i].size();}
        return count;
    }
};

int main() {
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(3,4);

    cout<<"In-degree of 3: "<<g.inDegree(3)<<"\n";
    g.adjacentVertices(1);
    cout<<"Total edges: "<<g.numberOfEdges()<<"\n";

    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 0=WHITE (undiscovered) 1=GRAY  (discovered) 2=BLACK (fully processed)
void BFS(vector<vector<int>>& adj, int s) {
    int n = adj.size();
    vector<int> color(n, 0);   // everyone is initially undiscovered
    vector<int> dist(n, -1);
    vector<int> parent(n, -1);
    queue<int> Q;
    color[s] = 1;      
    dist[s] = 0;
    Q.push(s);

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        // Explore all neighbors
        for (int v : adj[u]) {
            if (color[v] == 0) {   
                color[v] = 1;     
                dist[v] = dist[u] + 1;
                parent[v] = u;
                Q.push(v);
            }
        }
        color[u] = 2; 
    }
    // shortest paths obtained
    cout << "\nVertex  Distance  Parent\n";
    for (int i = 0; i < n; i++){
        cout<<i<<"\t"<< dist[i]<<"\t"<<parent[i]<<"\n";
    }
    cout<<"\nBFS Tree (edges):\n";
    for (int i = 0; i < n; i++) {
        if (parent[i] != -1) {
            cout<<parent[i]<<" -> "<<i<<"\n";
        }
    }
}

int main() {
    int n = 6;  
    vector<vector<int>> adj(n); //adjacency list
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0, 4};
    adj[3] = {1, 5};
    adj[4] = {1, 2, 5};
    adj[5] = {3, 4};
    int src_vtx=0;
    BFS(adj, src_vtx); 

    return 0;
}

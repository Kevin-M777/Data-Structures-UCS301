#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void prims(vector<vector<pair<int,int>>>& adj, int src) {
    int n = adj.size();
    vector<int> key(n, 1e9);
    vector<int> parent(n, -1);
    vector<bool> inMST(n, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    key[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (inMST[u]) continue;
        inMST[u] = true;
        for (auto edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            if (!inMST[v] && w < key[v]) { key[v] = w; key[v] = w; pq.push({key[v], v});}    
        }
    }
    cout<<"Edge  Weight\n";
    for (int v = 0; v < n; v++)
        if (parent[v] != -1)
            cout << parent[v] <<" "<<v<<" "<< key[v]<<"\n";
}

int main() {
    int n = 5;
    vector<vector<pair<int,int>>>adj(n);
    adj[0] = {{1,2},{3,6}};
    adj[1] = {{0,2},{2,3},{3,8},{4,5}};
    adj[2] = {{1,3},{4,7}};
    adj[3] = {{0,6},{1,8}};
    adj[4] = {{1,5},{2,7}};

    prims(adj, 0);
    return 0;
}

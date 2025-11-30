#include <iostream>
#include <vector>
using namespace std;
// 0=WHITE (undiscovered) 1=GRAY  (discovered) 2=BLACK (fully processed)
vector<int> color, parent, discover, finish;
int Time = 0;

void DFS_Visit(vector<vector<int>>& adj, int u) {
    color[u] = 1;
    discover[u] = ++Time;
    for (int v : adj[u]) {
        if (color[v] == 0) {parent[v] = u; DFS_Visit(adj, v);}
    }
    color[u] = 2;
    finish[u] = ++Time;
}

void DFS(vector<vector<int>>& adj){
    int n = adj.size();
    color.assign(n, 0);
    parent.assign(n, -1);
    discover.assign(n, 0);
    finish.assign(n, 0);
    Time = 0;
    for (int u = 0; u < n; u++)
        if (color[u] == 0)
            DFS_Visit(adj, u);
    cout << "Vertex Discover Finish Parent\n";
    for (int i = 0; i < n; i++)
        cout <<i<<"\t"<<discover[i]<<"\t"<<finish[i]<<"\t"<<parent[i]<<"\n";
    //display DFS tree
    for (int i = 0; i < n; i++)
        if (parent[i] != -1)
            cout <<parent[i]<<" "<<i<< "\n";
}

int main() {
    int n = 6;
    vector<vector<int>> adj(n); //adjacency list
    adj[0] = {1, 2};
    adj[1] = {3, 4};
    adj[2] = {4};
    adj[3] = {5};
    adj[4] = {5};
    adj[5] = {};

    DFS(adj);
    return 0;
}

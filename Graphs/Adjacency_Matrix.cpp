#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjm(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjm[u][v] = 1;
        adjm[v][u] = 1; // for undirected graph
    }
    return 0;
}
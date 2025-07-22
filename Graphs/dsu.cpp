#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1e5 + 7;
int parent[N];
int sz[N]; // size of the set
void make(int v)
{
    parent[v] = v;
    sz[v] = 1;
}
int find(int v)
{
    if (v == parent[v])
        return v;
    // path compression
    // this will make the tree flat, so that we can find the root faster next time
    return parent[v] = find(parent[v]);
}
void Union(int a, int b)
{
    // if a and b are already in the same set, do nothing
    a = find(a);
    b = find(b);
    // if a and b are in different sets, merge them
    // by making one the parent of the other
    if (a != b)
    {
        // union by size
        if (sz[a] < sz[b])
        {
            swap(a, b);
        }
        parent[b] = a;
        sz[a] += sz[b];
    }
}
// Time Complexity: O(logN) for find and union operations
int main()
{
    int n, k;
    // n=number of nodes, k=number of edges
    cin >> n >> k;
    // find the number of distinct connected components
    for (int i = 1; i <= n; i++)
    {
        make(i);
    }
    for (int i = 0; i < k; i++)
    {
        int u, v;
        cin >> u >> v;
        Union(u, v);
    }
    int distinctComponents = 0;
    for (int i = 1; i <= n; i++)
    {
        if (parent[i] == i) // if the node is its own parent, it is a root of a component
        {
            distinctComponents++;
        }
    }
    cout << distinctComponents << endl;
    return 0;
}
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

#define INF INT_MAX

int cost[100][100], dist[100];
bool vis[100];

int find_min(int n)
{
    int i, mn = INF, mn_pos = 0;

    for(i = 1; i <= n; ++i)
    {
        if(vis[i])
            continue;

        if(dist[i] < mn)
        {
            mn = dist[i];
            mn_pos = i;
        }
    }

    return i;
}

int main()
{
    int n, m, i, j, src, u, v, w, sz, adj_node;

    cout << "Enter the number of vertices: ";
    cin >> n;

    cout << "Enter the numbr of edges: ";
    cin >> m;

    for(i = 1; i <= n; ++i)
    {
        for(j = 1; j <= n; ++j)
        {
            cost[i][j] = INF;
        }
    }

    cout << "Enter the edges:\n";
    for(i = 0; i < m; ++i)
    {
        cin >> u >> v >> w;

        cost[u][v] = w;
        cost[v][u] = w;
    }

    cout << "Enter the source node: ";
    cin >> src;

    // PROCESSING
    for(i = 1; i <= n; ++i)
    {
        vis[i] = false;
        dist[i] = cost[src][i];
    }

    vis[src] = true;
    dist[src] = 0;

    for(i = 2; i <= n-1; ++i) // n-2 times, as distance of the src node and the adjacants of src node have been updated
    {
        u = find_min(n);

        vis[u] = true;

        for(j = 1; j <= n; ++j)
        {
            if(cost[u][j] == INF)   // not connected
                continue;

            if(dist[j] > dist[u] + cost[u][j])
                dist[j] = dist[u] + cost[u][j];
        }
    }

    // OUTPUT
    cout << "Shorted distance from " << src << " to -\n";
    
    for(i = 1; i <= n; ++i)
        cout << "Vertex " << i << ": " << dist[i] << '\n';
    
    return 0;
}
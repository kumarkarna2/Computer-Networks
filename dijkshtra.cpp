#include <bits/stdc++.h>
using std::cout, std::cin, std::endl;

int nodes, edges;
int graph[20][20];

void dijkstra(int nodes, int source)
{
    int distance[nodes];
    bool visited[nodes];
    for (int i = 1; i <= nodes; i++)
    {
        distance[i] = INT_MAX;
        visited[i] = false;
    }
    distance[source] = 0;

    for (int i = 1; i <= nodes - 1; i++)
    {
        int min = INT_MAX;
        int min_index;
        for (int j = 1; j <= nodes; j++)
        {
            if (visited[j] == false && distance[j] <= min)
            {
                min = distance[j];
                min_index = j;
            }
        }
        visited[min_index] = true;
        for (int j = 1; j <= nodes; j++)
        {
            if (visited[j] == false && graph[min_index][j] && distance[min_index] != INT_MAX && distance[min_index] + graph[min_index][j] < distance[j])
            {
                distance[j] = distance[min_index] + graph[min_index][j];
            }
        }
    }
    cout << "Node\tdistance from source" << endl;
    for (int i = 1; i <= nodes; i++)
    {
        cout << i << "\t" << distance[i] << endl;
    }
}
int main()
{
    // int edges, nodes;
    cout << "Enter the number of nodes and edges: ";
    cin >> nodes >> edges;

    for (int i = 1; i <= nodes; i++)
    {
        for (int j = 1; j <= nodes; j++)
        {
            graph[i][j] = 0;
        }
    }
    for (int i = 1; i <= edges; i++)
    {
        int s, d, w;
        cout << "Enter the edge nodes and weight: ";
        cin >> s >> d >> w;
        graph[s][d] = w;
        graph[d][s] = w;
    }
    int source;
    cout << "Enter the source node: ";
    cin >> source;
    dijkstra(nodes, source);

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int miniDistance(int dist[], bool visited[], int V) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void print(int dist[], int V) {
    cout << "Vertex Distance from Source\n";
    for (int i = 0; i < V; i++) {
        cout << i << " " << dist[i] << endl;
    }
}

void dijkstra(vector<vector<int>> graph, int src, int V) {
    int dist[V];
    bool visited[V] = {false};

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    for (int i = 0; i < V - 1; i++) {
        int u = miniDistance(dist, visited, V);
        visited[u] = true;
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    print(dist, V);
}

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;
    vector<vector<int>> graph(V, vector<int>(V));
    cout << "Enter adjacency matrix elements:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }
    dijkstra(graph, 0, V);
    return 0;
}

/*
Sample Output:
Enter number of vertices: 5
Enter adjacency matrix elements:
0 10 0 0 5
0 0 1 0 2
0 0 0 4 0
7 0 6 0 0
0 3 9 2 0
Vertex Distance from Source
0 0
1 8
2 9
3 7
4 5
*/

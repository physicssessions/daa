#include <bits/stdc++.h>
using namespace std;

void printSolution(vector<vector<int>> dist, int V) {
    cout << "The shortest distances between every pair of vertices:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INT_MAX)
                cout << "∞ ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

void floydWarshall(vector<vector<int>> dist, int V) {
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    printSolution(dist, V);
}

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;
    vector<vector<int>> graph(V, vector<int>(V));
    cout << "Enter adjacency matrix (-1 if no edge exists):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == -1) graph[i][j] = INT_MAX;
        }
    }
    floydWarshall(graph, V);
    return 0;
}

/*
Sample Output:
Enter number of vertices: 4
Enter adjacency matrix (-1 if no edge exists):
0 5 -1 10
-1 0 3 -1
-1 -1 0 1
-1 -1 -1 0
The shortest distances between every pair of vertices:
0 5 8 9
∞ 0 3 4
∞ ∞ 0 1
∞ ∞ ∞ 0
*/

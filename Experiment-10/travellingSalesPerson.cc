#include <bits/stdc++.h>
using namespace std;

int travellingSalesmanProblem(vector<vector<int>> graph, int s, int V) {
    vector<int> vertex;
    for (int i = 0; i < V; i++) {
        if (i != s) vertex.push_back(i);
    }

    int min_path = INT_MAX;
    do {
        int current_pathweight = 0;
        int k = s;
        for (int i = 0; i < vertex.size(); i++) {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }
        current_pathweight += graph[k][s];
        min_path = min(min_path, current_pathweight);
    } while (next_permutation(vertex.begin(), vertex.end()));

    return min_path;
}

int main() {
    int V, s;
    cout << "Enter number of vertices: ";
    cin >> V;
    vector<vector<int>> graph(V, vector<int>(V));
    cout << "Enter adjacency matrix of graph:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }
    cout << "Enter Source: ";
    cin >> s;

    cout << "Minimum cost of Travelling Salesman Problem: " << travellingSalesmanProblem(graph, s, V) << endl;
    return 0;
}

/*
Sample Output:
Enter number of vertices: 4
Enter adjacency matrix of graph:
0 10 15 20
10 0 35 25
15 35 0 30
20 25 30 0
Enter Source: 0
Minimum cost of Travelling Salesman Problem: 80
*/

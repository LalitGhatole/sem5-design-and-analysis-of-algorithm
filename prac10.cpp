#include <iostream>
#include <vector>

const int INF = INT_MAX;

void floydWarshall(std::vector<std::vector<int>>& graph, int numVertices) {
    // Initialize the distance matrix with the input graph
    std::vector<std::vector<int>> distance(numVertices, std::vector<int>(numVertices, 0));
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            distance[i][j] = graph[i][j];
        }
    }

    // Calculate shortest paths using dynamic programming
    for (int k = 0; k < numVertices; ++k) {
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                if (distance[i][k] != INF && distance[k][j] != INF && distance[i][k] + distance[k][j] < distance[i][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }

    // Print the shortest paths
    std::cout << "All-Pair Shortest Paths:" << std::endl;
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            if (distance[i][j] == INF) {
                std::cout << "INF\t";
            } else {
                std::cout << distance[i][j] << "\t";
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    int numVertices = 4;
    std::vector<std::vector<int>> graph = {
        {0, 3, INF, 0},
        {INF, 0, 1, 8},
        {INF, INF, 0, INF},
        {INF, 2, 4, 0}
    };

    floydWarshall(graph, numVertices);

    return 0;
}

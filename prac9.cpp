#include <iostream>
#include <vector>

struct Edge {
    int source, destination, weight;
};

void bellmanFord(std::vector<Edge>& edges, int numVertices, int source) {
    std::vector<int> distance(numVertices, INT_MAX);
    distance[source] = 0;

    for (int i = 0; i < numVertices - 1; ++i) {
        for (const Edge& edge : edges) {
            if (distance[edge.source] != INT_MAX && distance[edge.source] + edge.weight < distance[edge.destination]) {
                distance[edge.destination] = distance[edge.source] + edge.weight;
            }
        }
    }

    // Check for negative weight cycles
    for (const Edge& edge : edges) {
        if (distance[edge.source] != INT_MAX && distance[edge.source] + edge.weight < distance[edge.destination]) {
            std::cout << "Graph contains negative weight cycle." << std::endl;
            return;
        }
    }

    // Print shortest distances from the source
    std::cout << "Shortest distances from source vertex:" << std::endl;
    for (int i = 0; i < numVertices; ++i) {
        std::cout << "Vertex " << i << ": Distance = " << distance[i] << std::endl;
    }
}

int main() {
    int numVertices = 5;
    std::vector<Edge> edges = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };

    int sourceVertex = 0;
    bellmanFord(edges, numVertices, sourceVertex);

    return 0;
}

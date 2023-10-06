#include <iostream>
#include <list>
#include <queue>

class Graph {
private:
    int numVertices;
    std::list<int>* adjList;

public:
    Graph(int vertices) {
        numVertices = vertices;
        adjList = new std::list<int>[vertices];
    }

    void addEdge(int v, int w) {
        adjList[v].push_back(w);
        adjList[w].push_back(v);
    }

    void printGraph() {
        std::cout << "Graph (Adjacency List):" << std::endl;
        for (int i = 0; i < numVertices; i++) {
            std::cout << "Vertex " << i << " -> ";
            for (const auto& neighbor : adjList[i]) {
                std::cout << neighbor << " ";
            }
            std::cout << std::endl;
        }
    }

    void bfs(int startVertex) {
        bool* visited = new bool[numVertices];
        for (int i = 0; i < numVertices; i++) {
            visited[i] = false;
        }

        std::queue<int> queue;
        visited[startVertex] = true;
        queue.push(startVertex);

        std::cout << "Breadth-First Traversal (starting from vertex " << startVertex << "):" << std::endl;
        while (!queue.empty()) {
            int currentVertex = queue.front();
            std::cout << currentVertex << " ";
            queue.pop();

            for (const auto& neighbor : adjList[currentVertex]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue.push(neighbor);
                }
            }
        }

        delete[] visited;
    }
};

int main() {
    Graph graph(7); // Create a graph with 7 vertices

    // Add edges to the graph
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 5);
    graph.addEdge(3, 6);

    // Print the input graph (adjacency list)
    graph.printGraph();

    // Perform BFS traversal starting from vertex 0
    graph.bfs(0);

    return 0;
}

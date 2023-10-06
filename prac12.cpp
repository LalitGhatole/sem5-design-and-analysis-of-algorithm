#include <iostream>
#include <list>

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

    const std::list<int>& getAdjList(int vertex) const {
        return adjList[vertex];
    }

    void dfsUtil(int vertex, bool* visited) {
        visited[vertex] = true;
        std::cout << vertex << " ";

        for (const auto& neighbor : adjList[vertex]) {
            if (!visited[neighbor]) {
                dfsUtil(neighbor, visited);
            }
        }
    }

    void dfs(int startVertex) {
        bool* visited = new bool[numVertices];
        for (int i = 0; i < numVertices; i++) {
            visited[i] = false;
        }

        std::cout << "Depth-First Traversal (starting from vertex " << startVertex << "):" << std::endl;
        dfsUtil(startVertex, visited);

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

    std::cout << "Graph (Adjacency List):" << std::endl;
    for (int i = 0; i < 7; i++) {
        std::cout << "Vertex " << i << " -> ";
        for (const auto& neighbor : graph.getAdjList(i)) {
            std::cout << neighbor << " ";
        }
        std::cout << std::endl;
    }

    // Perform DFS traversal starting from vertex 0
    graph.dfs(0);

    return 0;
}

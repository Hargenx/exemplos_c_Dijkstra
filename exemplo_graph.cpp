#include <iostream>
#include <vector>
#include <queue>
#include <climits>

class Graph {
    int V;
    std::vector<std::pair<int, int>> *adj;

public:
    Graph(int V) : V(V) {
        adj = new std::vector<std::pair<int, int>>[V];
    }

    void addEdge(int u, int v, int weight) {
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }

    void dijkstra(int src) {
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
        std::vector<int> dist(V, INT_MAX);

        pq.push({0, src});
        dist[src] = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (auto i = adj[u].begin(); i != adj[u].end(); ++i) {
                int v = (*i).first;
                int weight = (*i).second;

                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        std::cout << "Distâncias mais curtas a partir de " << src << ":\n";
        for (int i = 0; i < V; ++i)
            std::cout << i << ": " << dist[i] << std::endl;
    }
};

int main() {
    int V = 5;
    Graph g(V);

    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 2);
    g.addEdge(1, 3, 3);
    g.addEdge(2, 3, 1);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 2);

    g.dijkstra(0);

    return 0;
}

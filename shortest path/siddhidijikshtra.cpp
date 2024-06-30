#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define INF 1000000
#define MAX_V 100
typedef pair<int, int> pii;
class Graph {
    int V;
    int adj[MAX_V][MAX_V];
public:
    Graph(int V) {
        this->V = V;
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                adj[i][j] = INF;
            }
        }
    }
    void addEdge(int u, int v, int w) {
        adj[u][v] = w;
        adj[v][u] = w;
    }
    void dijkstra(int source) {
        int dist[MAX_V];
        bool visited[MAX_V];

        for (int i = 0; i < V; ++i) {
            dist[i] = INF;
            visited[i] = false;
        }
        dist[source] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push(make_pair(0, source));
        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            if (visited[u]) {
                continue;
            }
            visited[u] = true;
            for (int v = 0; v < V; ++v) {
                if (adj[u][v] != INF) {
                    if (dist[u] + adj[u][v] < dist[v]) {
                        dist[v] = dist[u] + adj[u][v];
                        pq.push(make_pair(dist[v], v));
                    }
                }
            }
        }
        cout << "Shortest distances from source vertex " << source << ":\n";
        for (int i = 0; i < V; ++i) {
            cout <<"Vertex "<<i<<": "<<dist[i]<<"\n";
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0,1,4);
    g.addEdge(0,2,1);
    g.addEdge(1,2,2);
    g.addEdge(1,3,5);
    g.addEdge(2,3,2);
    g.addEdge(2,4,4);
    g.addEdge(3,4,3);
    int source=0;
    g.dijkstra(source);
    return 0;
}

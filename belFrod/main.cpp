#include <climits>
#include <iostream>

using namespace std;

class Edge {
public:
  int v1;
  int v2;
  int w;

  Edge() {
    v1 = -1;
    v2 = -1;
    w = INT_MAX;
  }

  Edge(int v1, int v2, int w) {
    this->v1 = v1;
    this->v2 = v2;
    this->w = w;
  }
};

void printDistances(int v, int *dist, int *prev) {
  for (int i = 0; i < v; i++) {
    int j = i;
    while (j != 0) {
      cout << j << " <- ";
      j = prev[j];
    }
    cout << "0"  << " with cost " << dist[i] << endl;
  }
}


void bellmanFroid(int v, int e, Edge *edges) {
  int *dist = new int[v];
  int *prev = new int[v];
  for (int i = 0; i < v; i++) {
    dist[i] = INT_MAX;
  }
  dist[0] = 0;
  for (int i = 0; i < v - 1; i++) {
    for (int j = 0; j < e; j++) {
      int u = edges[j].v1;
      int v = edges[j].v2;
      int w = edges[j].w;
      if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        prev[v] = u;
      }
    }
  }

  for (int i = 0; i < e; i++) {
    int u = edges[i].v1;
    int v = edges[i].v2;
    int w = edges[i].w;
    if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
      cout << "Graph contains negative weight cycle" << endl;
      return;
    }
  }

  printDistances(v, dist, prev);
}

int main() {
  cout << "Graph without negative weight cycle" << endl;
  int v = 4;
  int e = 5;
  Edge *edges = new Edge[e];
  edges[0] = Edge(0, 1, 1);
  edges[1] = Edge(0, 2, 4);
  edges[2] = Edge(1, 2, 2);
  edges[3] = Edge(2, 3, -3);
  edges[4] = Edge(1, 3, 2);
  bellmanFroid(v, e, edges);

  cout << "Graph with negative weight cycle" << endl;

  Edge *edges_with_cycle = new Edge[3];
  edges_with_cycle[0] = Edge(0, 1, -1);
  edges_with_cycle[1] = Edge(1, 2, -1);
  edges_with_cycle[2] = Edge(2, 0, -1);

  bellmanFroid(3, 3, edges_with_cycle);
  return 0;
}

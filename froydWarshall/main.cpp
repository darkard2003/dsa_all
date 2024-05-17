#include <climits>
#include <iostream>

using namespace std;

void froydWarshall(int V, int **graph, int **dist, int **path) {
  for (int i = 0; i < V; i++)
    for (int j = 0; j < V; j++)
      dist[i][j] = graph[i][j];
  for (int k = 0; k < V; k++) {
    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
        if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX &&
            dist[i][j] > dist[i][k] + dist[k][j])
          dist[i][j] = dist[i][k] + dist[k][j], path[i][j] = k;
      }
    }
  }
}

void printDistArr(int V, int **dist) {
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      if (dist[i][j] == INT_MAX)
        cout << "INF\t";
      else
        cout << dist[i][j] << "\t";
    }
    cout << endl;
  }
}

void printPath(int u, int v, int **path) {
  if (path[u][v] == 0)
    cout << u << " -> " << v << " ";
  else {
    printPath(u, path[u][v], path);
    cout << " -> " << v << " ";
  }
}

void printDist(int V, int u, int v, int **dist, int **path) {
  if (dist[u][v] == INT_MAX)
    cout << "No path from " << u << " to " << v << endl;
  else {
    printPath(u, v, path);
    cout << "\t";
    cout << "Cost: " << dist[u][v] << endl;
  }
}

int main(int argc, char *argv[]) {

  int V = 4;
  int **graph = new int *[V];
  for (int i = 0; i < V; i++)
    graph[i] = new int[V];

  for (int i = 0; i < V; i++)
    for (int j = 0; j < V; j++)
      graph[i][j] = INT_MAX;

  graph[0][1] = 5;
  graph[0][2] = 10;
  graph[1][2] = 3;
  graph[1][3] = 2;
  graph[2][3] = 1;

  int **dist = new int *[V];
  for (int i = 0; i < V; i++)
    dist[i] = new int[V];

  int **path = new int *[V];
  for (int i = 0; i < V; i++)
    path[i] = new int[V];

  froydWarshall(V, graph, dist, path);

  printDistArr(V, dist);

  cout << endl;
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      printDist(V, i, j, dist, path);
    }
  }

  return 0;
}

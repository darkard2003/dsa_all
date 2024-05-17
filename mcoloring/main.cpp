#include <iostream>

using namespace std;

bool isSafe(int c, int *colors, int **graph, int v, int V) {
  for (int i = 0; i < V; i++) {
    if (graph[v][i] && c == colors[i]) {
      return false;
    }
  }
  return true;
}

void printColors(int *colors, int V) {
  for (int i = 0; i < V; i++) {
    cout << colors[i] << " ";
  }
  cout << endl;
}

void colorGraphUntill(int **graph, int V, int m, int v, int *colors) {
  if (v == V) {
    printColors(colors, V);
    return;
  }
  for (int c = 1; c <= m; c++) {
    if (isSafe(c, colors, graph, v, V)) {
      colors[v] = c;
      colorGraphUntill(graph, V, m, v + 1, colors);
      colors[v] = 0;
    }
  }
}

int main() {
  int V = 4;
  int m = 3;
  int **graph = new int *[V];
  for (int i = 0; i < V; i++) {
    graph[i] = new int[V];
    for (int j = 0; j < V; j++) {
      graph[i][j] = 0;
    }
  }
  graph[0][1] = 1;
  graph[0][2] = 1;
  graph[1][0] = 1;
  graph[1][2] = 1;
  graph[2][0] = 1;
  graph[2][1] = 1;
  graph[2][3] = 1;
  graph[3][2] = 1;
  int *colors = new int[V]{0};
  // for (int i = 0; i < V; i++) {
  //   colors[i] = 0;
  // }
  colorGraphUntill(graph, V, m, 0, colors);
  return 0;
}

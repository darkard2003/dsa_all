#include <climits>
#include <fstream>
#include <iostream>

using namespace std;

int minKey(int key[], bool mstSet[], int V) {
  int minValue = INT_MAX, minIdx;
  for (int v = 0; v < V; v++)
    if (mstSet[v] == false && key[v] < minValue)
      minValue = key[v], minIdx = v;
  return minIdx;
}

void printMST(int parent[], int V, int **graph) {
  cout << "Edge \t Weight" << endl;
  for (int i = 1; i < V; i++) {
    if (parent[i] != -1) {
      cout << parent[i] << " -> " << i << " \t " << graph[parent[i]][i] << endl;
    }
  }
}

void primsMST(int V, int **graph) {
  int *key = new int[V];
  int *parent = new int[V];
  bool *mstSet = new bool[V];

  for (int i = 0; i < V; i++)
    key[i] = INT_MAX, mstSet[i] = false;

  key[0] = 0;
  parent[0] = -1;

  for (int i = 0; i < V - 1; i++) {
    int u = minKey(key, mstSet, V);
    mstSet[u] = true;

    for (int v = 0; v < V; v++) {
      if (graph[u][v] && !mstSet[u] && graph[u][v] < key[v])
        key[v] = graph[u][v], parent[v] = u;
    }
  }

  printMST(parent, V, graph);

  delete[] key;
  delete[] parent;
  delete[] mstSet;
}

int main() {
  int **graph;
  fstream file;
  file.open("mat.txt");
  if (!file.is_open()) {
    cout << "Error opening file" << endl;
    return 1;
  }
  int s;
  file >> s;
  graph = new int *[s];
  for (int i = 0; i < s; i++) {
    graph[i] = new int[s];
    for (int j = 0; j < s; j++) {
      file >> graph[i][j];
    }
  }
  file.close();

  primsMST(s, graph);

  return 0;
}

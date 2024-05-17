#include <climits>
#include <fstream>
#include <iostream>

int minKey(int *key, bool *mstSet, int V)
{
  int min = INT_MAX, min_index;
  for (int v = 0; v < V; v++)
    if (mstSet[v] == false && key[v] < min)
      min = key[v], min_index = v;
  return min_index;
}

void printShortestPath(int *parent, int e)
{
  if (parent[e] == -1)
    return;
  printShortestPath(parent, parent[e]);
  std::cout << e << " ";
}

int getEnd(int *parent, int start, int v)
{
  int child = -1;
  for (int i = 0; i < v; i++)
    if (parent[i] == start)
    {
      child = i;
      break;
    }
  if (child == -1)
    return start;
  return getEnd(parent, child, v);
}

void printMST(int *parent, int **graph, int V)
{
  std::cout << "Edge \tWeight\n";
  for (int i = 1; i < V; i++)
    std::cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << std::endl;
}

void shortestPath(int V, int **graph)
{
  int *key = new int[V];
  int *parent = new int[V];
  bool *mstSet = new bool[V];
  for (int i = 0; i < V; i++)
    key[i] = INT_MAX, mstSet[i] = false;
  key[0] = 0;
  parent[0] = -1;
  for (int i = 0; i < V - 1; i++)
  {
    int u = minKey(key, mstSet, V);
    mstSet[u] = true;
    for (int v = 0; v < V; v++)
      if (graph[u][v] && !mstSet[v] && key[u] + graph[u][v] < key[v])
        key[v] = graph[u][v] + key[u], parent[v] = u;
  }
  int end = getEnd(parent, 0, V);
  std::cout << "Shortest Path: ";
  printShortestPath(parent, end);
  printMST(parent, graph, V);
  delete[] key;
  delete[] parent;
  delete[] mstSet;
}

int main()
{
  int **graph;
  std::fstream file;
  file.open("mat.txt");
  if (!file.is_open())
  {
    std::cout << "Error opening file" << std::endl;
    return 1;
  }
  int s;
  file >> s;
  graph = new int *[s];
  for (int i = 0; i < s; i++)
  {
    graph[i] = new int[s];
    for (int j = 0; j < s; j++)
      file >> graph[i][j];
  }
  shortestPath(s, graph);
  for (int i = 0; i < s; i++)
    delete[] graph[i];
  delete[] graph;
  file.close();

  return 0;
}

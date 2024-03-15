#include <iostream>

#include "graph.cpp"

void test()
{
  Graph g(5);
  g.addEdge(0, 1);
  g.addEdge(1, 2);
  g.addEdge(1, 3);
  g.addEdge(2, 3);
  g.addEdge(3, 4);

  cout << "BFS: ";
  g.BFS();
  // cout << "DFS: ";
  // g.DFS();
  cout << "DFS no recurse: ";
  g.DFS(false);

  // cout << "All paths: " << endl;
  // g.printAllPaths(0, 3);

  cout << "All paths no recurse: " << endl;
  g.printAllPaths(0, 3, false);
}

int main()
{
  test();
  return 0;
}

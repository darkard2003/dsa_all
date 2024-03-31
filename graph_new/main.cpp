#include "graph.cpp"

using namespace std;

int main(){
  Graph g(5);

  g.addEdge(5, 0);
  g.addEdge(5, 2);
  g.addEdge(4, 0);
  g.addEdge(4, 1);
  g.addEdge(2, 3);
  g.addEdge(3, 1);

  g.topSort();
  return 0;
}


#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Vertex {
public:
  int data;
  Vertex *next;

  Vertex(int data) {
    this->data = data;
    next = NULL;
  }
};

class Graph {
  Vertex **verticies;
  int size;

public:
  Graph(int size) {
    this->size = size;
    verticies = new Vertex *[size];
    for (int i = 0; i < size; i++) {
      verticies[i] = NULL;
    }
  }

  void addEdge(int src, int dest) {
    Vertex *vertex = new Vertex(dest);
    vertex->next = verticies[src];
    verticies[src] = vertex;
  }

  void printGraph() {
    for (int i = 0; i < size; i++) {
      Vertex *temp = verticies[i];
      while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
      }
      cout << endl;
    }
  }

  void BFS() {
    bool *visited = new bool[size]{false};
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while (!q.empty()) {
      int current = q.front();
      cout << current << " ";
      q.pop();
      Vertex *temp = verticies[current];
      while (temp != NULL) {
        if (!visited[temp->data]) {
          q.push(temp->data);
          visited[temp->data] = true;
        }
        temp = temp->next;
      }
    }
  }

  void DFS() {
    bool *visited = new bool[size]{false};
    stack<int> s;
    s.push(0);
    visited[0] = true;
    while (!s.empty()) {
      int current = s.top();
      cout << current << " ";
      s.pop();
      Vertex *temp = verticies[current];
      while (temp != NULL) {
        if (!visited[temp->data]) {
          s.push(temp->data);
          visited[temp->data] = true;
        }
        temp = temp->next;
      }
    }
  }

  void topSort() {
    queue<int> q;
    int *indegree = new int[size]{0};
    int *visited = new int[size]{0};

    for (int i = 0; i < size; i++) {
      Vertex *temp = verticies[i];
      while (temp != NULL) {
        indegree[temp->data]++;
        temp = temp->next;
      }
    }

    for (int i = 0; i < size; i++) {
      if (indegree[i] == 0) {
        q.push(i);
        visited[i] = 1;
      }
    }

    while (!q.empty()) {
      int current = q.front();
      cout << current << " ";
      q.pop();
      Vertex *temp = verticies[current];
      while (temp != NULL) {
        indegree[temp->data]--;
        if (indegree[temp->data] == 0 && visited[temp->data] == 0) {
          q.push(temp->data);
          visited[temp->data] = 1;
        }
        temp = temp->next;
      }
    }

    // Check if cycle is present
    for (int i = 0; i < size; i++) {
      if (visited[i] == 0) {
        cout << i << " ";
      }
    }
  }
};

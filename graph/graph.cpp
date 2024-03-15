#include <iostream>
#include <stack>
#include <list>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Edge
{
public:
  int source;
  int destination;

  Edge() : source(0), destination(0) {}

  Edge(int source, int destination)
  {
    this->source = source;
    this->destination = destination;
  }
};

class Graph
{
  vector<Edge> *verticis;
  int size;

public:
  Graph(int size)
  {
    verticis = new vector<Edge>[size];
    this->size = size;
  }

  bool edgeExists(int source, int destination)
  {
    for (auto edge : verticis[source])
    {
      if (edge.destination == destination)
      {
        return true;
      }
    }
    return false;
  }

  void addEdge(int source, int destination, bool bidirectional = true)
  {
    if (edgeExists(source, destination))
    {
      return;
    }
    verticis[source].push_back(Edge(source, destination));
    if (bidirectional)
      verticis[destination].push_back(Edge(destination, source));
  }

  void BFS()
  {
    queue<int> q;
    vector<bool> visited(verticis->size(), false);

    q.push(0);
    visited[0] = true;

    while (!q.empty())
    {
      int current = q.front();
      cout << current << " ";
      q.pop();
      for (auto edge : verticis[current])
      {
        if (!visited[edge.destination])
        {
          q.push(edge.destination);
          visited[edge.destination] = true;
        }
      }
    }

    cout << endl;
  }

  void DFS(bool recurse = true)
  {
    if (recurse)
    {
      bool *visited = new bool[size];
      for (int i = 0; i < size; i++)
        visited[i] = false;
      visited[0] = true;
      _dfs(verticis, 0, visited);
      delete[] visited;
    }
    else
      _dfs_no_recurse();
    cout << endl;
  }

  vector<string> getAllPaths(int s, int d, bool recurse = true)
  {
    if (!recurse)
      return _all_paths_no_recurse(s, d);
    vector<string> paths;

    bool *visited = new bool[size];
    for (int i = 0; i < size; i++)
      visited[i] = false;

    visited[s] = true;

    _all_paths(verticis, s, d, visited, "", paths);

    delete[] visited;

    return paths;
  }

  void printAllPaths(int s, int d, bool recurse = true)
  {
    vector<string> paths = getAllPaths(s, d, recurse);

    for (auto p : paths)
    {
      cout << p << endl;
    }
  }

  void _dfs(vector<Edge> *graph, int current, bool visited[])
  {
    cout << current << " ";

    for (auto i : graph[current])
    {
      if (visited[i.destination] == false)
      {
        visited[i.destination] = true;
        _dfs(graph, i.destination, visited);
      }
    }
  }

  void _dfs_no_recurse()
  {
    vector<int> s;
    vector<bool> visited(verticis->size(), false);
    visited[0] = true;
    s.push_back(0);

    while (!s.empty())
    {
      int c = s.back();
      s.pop_back();

      cout << c << " ";

      for (auto i : verticis[c])
      {
        if (!visited[i.destination])
        {
          visited[i.destination] = true;
          s.push_back(i.destination);
        }
      }
    }
    cout << endl;
  }

  void _all_paths(vector<Edge> graph[], int c, int d, bool visited[],
                  string trail, vector<string> &paths)
  {
    trail.append(to_string(c));

    if (c == d)
    {
      paths.push_back(trail);
      return;
    }

    trail.append("->");

    for (auto i : graph[c])
    {
      if (!visited[i.destination])
      {
        visited[i.destination] = true;
        _all_paths(graph, i.destination, d, visited, trail, paths);
        visited[i.destination] = false;
      }
    }
  }

  vector<string> _all_paths_no_recurse(int so, int de)
  {
    vector<bool> visited(size, false);
    deque<int> s;

    vector<string> paths;
    paths.reserve(size); // if you have an estimate of the number of paths

    s.push_back(so);

    string trace = "";

    while (!s.empty())
    {
      int c = s.back();
      s.pop_back();

      if (visited[c])
      {
        visited[c] = false;
        if (!trace.empty())
        {
          trace = trace.substr(0, trace.rfind(" -> ")); // remove the last arrow and number
          trace.append(" -> ");                         // add the arrow back
        }
        continue;
      }

      visited[c] = true;
      trace.append(to_string(c) + " -> ");

      for (auto e : verticis[c])
      {
        if (e.destination == de)
        {
          string temp_trace = trace;
          temp_trace.append(to_string(e.destination));
          paths.emplace_back(temp_trace);
          continue;
        }
        if (!visited[e.destination])
          s.push_back(e.destination);
      }
    }

    return paths;
  }
};

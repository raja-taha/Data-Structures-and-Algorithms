// DFS algorithm in C++

#include <iostream>
#include <list>
using namespace std;

class Graph {
    int numVertices;
    list<int> *adjLists;
    bool *visited;

    public:
    Graph(int vertices) {
        numVertices = vertices;
        adjLists = new list<int>[vertices];
        visited = new bool[vertices];
    }

    void addEdge(int src, int dest) {
        adjLists[src].push_front(dest);
        adjLists[dest].push_front(src);
    }

    void DFS(int vertex) {
        visited[vertex] = true;
        list<int> adjList = adjLists[vertex];

        cout << vertex << " ";

        list<int>::iterator i;
        for (i = adjList.begin(); i != adjList.end(); ++i){
            if (!visited[*i]){
                DFS(*i);
            }
        }
    }
};

int main() {
  Graph g(7);
  g.addEdge(0, 1);
  g.addEdge(0, 3);
  g.addEdge(1, 2);
  g.addEdge(2, 3);
  g.addEdge(2, 4);
  g.addEdge(4, 5);
  g.addEdge(4, 6);

  g.DFS(0);

  return 0;
}
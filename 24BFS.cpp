// BFS algorithm in C++

#include <iostream>
#include <list>

using namespace std;

class Graph {
    int numVertices;
    list<int>* adjLists;
    bool* visited;

    public:
    Graph(int vertices) {
        numVertices = vertices;
        adjLists = new list<int>[vertices];
    }

    void addEdge(int src, int dest) {
        adjLists[src].push_back(dest);
        adjLists[dest].push_back(src);
    }

    void BFS(int startVertex) {
        visited = new bool[numVertices];
        for (int i = 0; i < numVertices; i++){
            visited[i] = false;
        }
        list<int> queue;

        visited[startVertex] = true;
        queue.push_back(startVertex);

        list<int>::iterator i;

        while (!queue.empty()) {
            int currVertex = queue.front();
            cout << "Visited " << currVertex << " ";
            queue.pop_front();

            for (i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i) {
                int adjVertex = *i;
                if (!visited[adjVertex]) {
                    visited[adjVertex] = true;
                    queue.push_back(adjVertex);
                }
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

  g.BFS(0);

  return 0;
}
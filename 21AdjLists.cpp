// Adjascency List representation in C++

#include <iostream>
#include <list>
using namespace std;

void addEdge(list<int> adj[], int s, int d) {
    adj[s].push_back(d);
    adj[d].push_back(s);
}

void printGraph(list<int> adj[], int V) {
    for (int d = 0; d < V; ++d) {
        cout << "\n Vertex "<< d << ":";

        list<int> adjj = adj[d];
        list<int>::iterator i;

        for (i = adjj.begin(); i != adjj.end(); ++i){
            cout << "-> " << *i;
        }
        printf("\n");
    }
}

int main() {
  int V = 5;

  // Create a graph
  list<int> adj[V];

  // Add edges
  addEdge(adj, 0, 1);
  addEdge(adj, 0, 2);
  addEdge(adj, 0, 3);
  addEdge(adj, 1, 2);
  printGraph(adj, V);
}
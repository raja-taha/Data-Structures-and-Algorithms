#include<iostream>
#include<list>
#include<vector>
#include<queue>

using namespace std;

# define INF 0x3f3f3f3f

// Creating an integer pair
typedef pair<int, int> edge;

// Adjacency List representation of a directed Graph
class Graph {
	int V;

	// Vertex and Weight pair for every edge
	list< pair<int, int> > *adj;

public:
	Graph(int Ver){
		V = Ver;

		// Creating a List for every vertex
		adj = new list<edge> [V];
	}

	// Function to add an edge to the adjacency list
	void addEdge(int u, int v, int w) {
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}

	void primMST();

	void menu();
};

void Graph::primMST()
{
	// max-heap can be implemented using simple priority queue
	// To make it min-heap priority_queue supports a constructor
	// that requires two extra arguments
	priority_queue< edge, vector <edge> , greater<edge> > pq;

	int src = 0;

	// Create a vector for keys and initialize all keys as infinite
	vector<int> key(V, INF);

	// To store parent array which in turn store MST
	vector<int> parent(V, -1);

	// To keep track of vertices included in MST
	vector<bool> inMST(V, false);

	// Insert source itself in priority queue and initialize its key as 0.
	pq.push(make_pair(0, src));
	key[src] = 0;

	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		
		if(inMST[u] == true){
			continue;
		}
		
		inMST[u] = true;

		list< pair<int, int> >::iterator i;

		for (i = adj[u].begin(); i != adj[u].end(); ++i) {

			// Get vertex label and weight of current adjacent of u.
			int v = (*i).first;
			int weight = (*i).second;

			// If v is not in MST and weight of (u,v) is smaller than current key of v
			if (inMST[v] == false && key[v] > weight) {
				// Updating key of v
				key[v] = weight;
				pq.push(make_pair(key[v], v));
				parent[v] = u;
			}
		}
	}

	// Print edges of MST using parent array
	for (int i = 1; i < V; ++i){
		cout<< parent[i] << " - " << i<<endl;
	}

	vector<int>::iterator it;
	int totalCost = 0;
	for(it = key.begin(); it != key.end(); ++it){
		totalCost += *it;
	}
	cout<<"Total cost: "<<totalCost;

}

void Graph::menu(){
    cout<<"\nEnter 1 to add edge.\n";
    cout<<"Enter 2 to run Prims.\n";

    cout<<"Enter an option: ";
    int option;
    cin>>option;

    switch(option) {
        case 1:
            int x1, y1, w1;
            cout<<"Enter edge (Start <Space> End <Space> Weight): ";
            cin>>x1 >> y1 >> w1;
            addEdge(x1, y1, w1);
            menu();
        case 2:{
			cout << "Edges of MST are \n";
			primMST();
            menu();
		}
        default:
            menu();
    }
}

int main() {
	cout<<"Enter the number of vertices: ";
    int ver;
    cin>>ver;
	
	Graph g(ver);

	g.menu();

	return 0;
}
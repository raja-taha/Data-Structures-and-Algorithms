#include<bits/stdc++.h>

using namespace std;

// Creating an integer pair
typedef pair<int, int> edge;

struct DisjointSets {
	int *parent, *rank;
	int n;

	DisjointSets(int x){
		n = x;
		parent = new int[n+1];
		rank = new int[n+1];

		for (int i = 0; i <= n; i++){
			rank[i] = 0;
			
			parent[i] = i;	//Every element is parent of itself
		}
	}

	// findParent the parent
	int findParent(int u){
		if (u != parent[u]){
			parent[u] = findParent(parent[u]);
		}
		return parent[u];
	}

	// Union by rank
	void merge(int x, int y)
	{
		x = findParent(x), y = findParent(y);

		/* Make tree with smaller height
		a subtree of the other tree */
		if (rank[x] > rank[y]){
			parent[y] = x;
		}
		else {
			// If rnk[x] <= rnk[y]
			parent[x] = y;
		}

		if (rank[x] == rank[y]){
			rank[y]++;
		}
	}
};

// Structure to represent a graph
struct Graph{
	int V, E;
	vector< pair<int, edge> > weightedEdges;

	Graph(int Ver){
		V = Ver;
	}

	void addEdge(int u, int v, int w){
		weightedEdges.push_back({w, {u, v}});
	}

	int kruskalMST();

	void menu();
};

int Graph::kruskalMST() {
	int cost = 0;

	// Sort edges on basis of cost
	sort(weightedEdges.begin(), weightedEdges.end());

	DisjointSets ds(V);

	vector< pair<int, edge> >::iterator it;

	for (it=weightedEdges.begin(); it!=weightedEdges.end(); it++){
		int u = it->second.first;
		int v = it->second.second;

		int parent_u = ds.findParent(u);
		int parent_v = ds.findParent(v);

		// Cycle is created if u and v belong to same set
		if (parent_u != parent_v){
			cout << u << " - " << v << " = " << it->first<< endl;

			cost += it->first;

			ds.merge(parent_u, parent_v);
		}
	}

	return cost;
}

void Graph::menu(){
    cout<<"\nEnter 1 to add edge.\n";
    cout<<"Enter 2 to run Kruskal.\n";

    cout<<"Enter an option: ";
    int option;
    cin>>option;

    switch(option){
        case 1:
            int x1, y1, w1;
            cout<<"Enter edge (Start <Space> End <Space> Weight): ";
            cin>>x1 >> y1 >> w1;
            addEdge(x1, y1, w1);
            menu();
        case 2:{
			cout << "Edges of MST are \n";
			int totalCost = kruskalMST();

			cout << "\nWeight of MST is " << totalCost;
            menu();
		}
        default:
            menu();
    }
}

int main(){
	cout<<"Enter the number of vertices: ";
    int ver;
    cin>>ver;
	Graph g(ver);

	g.menu();

	return 0;
}
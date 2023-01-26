#include <iostream>
using namespace std;

class Graph {
    private:
    int** adjMatrix;
    int numVertices;

    public:
    Graph(int numVertices) {
        this->numVertices = numVertices;
        adjMatrix = new int*[numVertices];

        for (int i = 0; i < numVertices; i++) {
            adjMatrix[i] = new int[numVertices];

            for (int j = 0; j < numVertices; j++){
                adjMatrix[i][j] = 0;
            }
        }
    }

    void addEdge(int i, int j) {
        adjMatrix[i][j] += 1;
        adjMatrix[j][i] += 1;
    }

    void removeEdge(int i, int j) {
        if(adjMatrix[i][j] > 0 && adjMatrix[j][i] > 0){
            adjMatrix[i][j] -= 1;
            adjMatrix[j][i] -= 1;
        }
        else{
            cout<<"No edge"<<endl;
        }
    }

    void toString() {
        for (int i = 0; i < numVertices; i++) {
            cout << i << " : ";
            for (int j = 0; j < numVertices; j++){
                cout << adjMatrix[i][j] << " ";
            }
            cout << "\n";
        }
    }

    int degGraph(){
        int deg = 0;
        for(int i=0; i<numVertices; i++){
            for(int j=0; j<numVertices; j++){
                if(i==j && adjMatrix[i][j]>0){
                    deg += 2*adjMatrix[i][j];	
                }
                else{
                    deg += adjMatrix[i][j];
                }
            }
        }
        return deg;
    }

    int degVertix(int x){
        int deg = 0;
        for(int i=0; i<numVertices; i++){
            if(adjMatrix[i][i]>0){
                deg += 2*adjMatrix[x][i];	
            }
            else{
                deg += adjMatrix[x][i];
            }
        }
        return deg;
    }

    void typeGraph(){
        int pseudo = 0;
        int multi = 0;
        int symmetric = 0;

        for(int i=0; i<numVertices; i++){
            for(int j=i+1; j<numVertices; j++){
                if(adjMatrix[i][i]>0){
                    pseudo = 1;
                }
                if(adjMatrix[i][j]>1){
                    multi = 1;
                }
                if(adjMatrix[i][j] == adjMatrix[j][i]){
                    symmetric = 1;
                }
            }
        }

        if(multi==0){
            cout<<"Graph is Simple." << endl;
        }
        else{
            cout<<"Graph is Multi." << endl;
        }
        if(pseudo != 0){
            cout<<"Graph is Pesudo." << endl;
        }
        if(symmetric != 0){
            cout<<"Graph is Symmetric." << endl;
        }
    }

    ~Graph() {
        for (int i = 0; i < numVertices; i++){
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }

    void menu(){
        cout<<"\nEnter 1 to add edge.\n";
        cout<<"Enter 2 to remove edge.\n";
        cout<<"Enter 3 to diplay graph.\n";
        cout<<"Enter 4 to display degree of graph.\n";
        cout<<"Enter 5 to display degree of vertex.\n";
        cout<<"Enter 6 to display type of graph.\n";

        cout<<"Enter an option: ";
        int option;
        cin>>option;

        switch(option){
            case 1:
                int x1, y1;
                cout<<"Enter edge starting and ending point: ";
                cin>>x1 >> y1;
                addEdge(x1, y1);
                menu();
            case 2:
                int x2, y2;
                cout<<"Enter edge starting and ending point: ";
                cin>>x2 >> y2;
                removeEdge(x2, y2);
                menu();
            case 3:
                toString();
                menu();
            case 4:
                cout<<"Degree of graph is: "<<degGraph()<<endl;
                menu();
            case 5:
                int x3;
                cout<<"Enter a vertex: ";
                cin>>x3;
                cout<<"Degree of vertex is: "<<degVertix(x3)<<endl;
                menu();
            case 6:
                typeGraph();
                menu();
            default:
                menu();
        }
    }
};

int main() {
    cout<<"Enter the number of vertices: ";
    int ver;
    cin>>ver;
    Graph g(ver);

    g.menu();
}
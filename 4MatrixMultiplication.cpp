#include <iostream>
using namespace std;

int main(){
	int rows, cols;
	cout<<"Enter number of rows: ";
	cin>>rows;
	cout<<"Enter number of columns: ";
	cin>>cols;
	
	int matrix1[rows][cols];
	int matrix2[rows][cols];
	int resultant[rows][cols];
	
	//First Matrix
	cout<<"\nEnter values for first matrix:\n";
	for(int i = 0; i<rows; i++){
		for(int j = 0; j<cols; j++){
			cin>>matrix1[i][j];
		}
	}
	
	//Second Matrix
	cout<<"\nEnter values for second matrix:\n";
	for(int i = 0; i<rows; i++){
		for(int j = 0; j<cols; j++){
			cin>>matrix2[i][j];
		}
	}
	
	//Resultant
	cout<<"\nResultant matrix:\n";
	for(int i = 0; i<rows; i++){
		for(int j = 0; j<cols; j++){
			resultant[i][j] = matrix1[i][j] * matrix2[i][j];
			cout<< resultant[i][j] << " ";
		}
		cout<<endl;
	}
	
	return 0;
}

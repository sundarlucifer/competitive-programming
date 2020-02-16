#include <iostream>
using namespace std;

const int matrixSize = 4;

void rotateMatrix(int matrix[][matrixSize]){
    int tempBuffer;
    for(int i=0; i<matrixSize/2; i++){
        for(int j=i; j<matrixSize-i-1; j++){
            tempBuffer = matrix[i][j];
            
            matrix[i][j] = matrix[j][matrixSize-i-1];
            matrix[j][matrixSize-i-1] = matrix[matrixSize-i-1][matrixSize-j-1];
            matrix[matrixSize-i-1][matrixSize-j-1] = matrix[matrixSize-j-1][i];
            matrix[matrixSize-j-1][i] = tempBuffer;
        }
    }
    
    cout << "Rotated matrix by 90 degrees" << endl;
}

void printMatrix(int matrix[][matrixSize]){
    for(int i=0; i<matrixSize; i++){
        for(int j=0; j<matrixSize; j++)
            printf("%2d ", matrix[i][j]);
        cout << endl;
    }
}

int main(){
    
    int matrix[matrixSize][matrixSize] = {  {1, 2, 3, 4},
                                            {5, 6, 7, 8},
                                            {9, 10, 11, 12},
                                            {13, 14, 15, 16} };
    
    printMatrix(matrix);
    
    rotateMatrix(matrix);
    
    printMatrix(matrix);
    
    return 0;
}

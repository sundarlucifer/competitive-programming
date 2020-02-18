#include <iostream>
using namespace std;

const int SIZE = 4;

void zeroMatrix(int matrix[][SIZE]){
    bool rowBook[SIZE] = {0};
    bool colBook[SIZE] = {0};
    for(int i=0; i<SIZE; i++)
        for (int j=0; j<SIZE; j++)
            if(matrix[i][j] == 0)
                rowBook[i] = colBook[j] = 1;
    for(int i=0; i<SIZE; i++)
        for (int j=0; j<SIZE; j++)
            if(rowBook[i] || colBook[j])
                matrix[i][j] = 0;
}

void printMatrix(int matrix[][SIZE]){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++)
            printf("%2d ", matrix[i][j]);
        cout << endl;
    }
}

int main(){
    
    int matrix[SIZE][SIZE] = {
        {1, 1, 0, 3},
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 1},
    };
    
    zeroMatrix(matrix);
    
    printMatrix(matrix);
    
    return 0;
}

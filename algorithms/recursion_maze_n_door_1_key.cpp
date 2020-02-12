// Maze with n doors and 1 key
// Refer : https://www.geeksforgeeks.org/maze-with-n-doors-and-1-key/
# include <iostream>
using namespace std;

bool searchDest(int* maze, int x, int y, int n, bool hasKey){

    if(x<0 || y<0 || x>=n || y>=n)  // out of range
        return false;

    if(*((maze+x*n)+y) == 1){       // Door locked
        if(!hasKey)
            return false;
        if(x==n-1 && y==n-1)        // reached destination
            return true;
        return searchDest(maze, x+1, y, n, false) || searchDest(maze, x, y+1, n, false);
    }

    if(x==n-1 && y==n-1)        // reached destination
        return true;

    return searchDest(maze, x+1, y, n, hasKey) || searchDest(maze, x, y+1, n, hasKey);
}

bool solveMaze(int* maze, int n){
    if(searchDest(maze, 0, 0, n, true))
        return true;
    else
        return false;
}

int main(){
    int maze[3][3]={{0,0,1},{1,0,1},{1,1,1}};
    cout << "Destination reachable ? ";
    if(solveMaze(&maze[0][0], 3))
        cout << "Yes";
    else
        cout << "No";
    cout << endl;
    return 0;
}
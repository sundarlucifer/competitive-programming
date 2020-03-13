// may fail in case of cycles in graph
#include <iostream>
using namespace std;

struct GraphEntry{
    int vertex;
    GraphEntry* next;
};

struct Graph{
    int numberOfVertices;
    GraphEntry** vertexList;
};

GraphEntry* newGraphEntry(int vertex){
    GraphEntry* graphEntry = new GraphEntry();
    graphEntry->vertex = vertex;
    graphEntry->next = NULL;
    return graphEntry;
}

Graph* newGraph(int numberOfVertices){
    Graph* graph = new Graph();
    graph->numberOfVertices = numberOfVertices;
    graph->vertexList = (GraphEntry**) malloc(numberOfVertices * sizeof(GraphEntry*));
    for(int i=0; i<numberOfVertices; i++){
        graph->vertexList[i] = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, int source, int destination){
    if(graph->vertexList[source] == NULL){
        graph->vertexList[source] = newGraphEntry(destination);
        return;
    }
    GraphEntry* newEntry = newGraphEntry(destination);
    newEntry->next = graph->vertexList[source];
    graph->vertexList[source] = newEntry;
}

bool hasRoute(Graph* graph, int source, int destination){
    cout << "Searching route : " << source << " to " << destination << endl;

    bool foundRoute = false;
    GraphEntry* ptrVertex = graph->vertexList[source];
    while(ptrVertex != NULL){
        if(ptrVertex->vertex == destination)
            return true;
        foundRoute = hasRoute(graph, ptrVertex->vertex, destination);
        if(foundRoute)
            return true;
        ptrVertex = ptrVertex->next;
    }

    return foundRoute;
}

void printAllEdges(Graph* graph){
    for(int i=0; i<graph->numberOfVertices; i++){
        GraphEntry* ptrVertex = graph->vertexList[i];
        cout << i << " : ";
        while(ptrVertex!=NULL){
            printf("%d ", ptrVertex->vertex);
            ptrVertex = ptrVertex->next;
        }
    }
}

int main(){

    Graph* myGraph = newGraph(5);
    addEdge(myGraph, 0, 1);
    addEdge(myGraph, 0, 2);
    addEdge(myGraph, 1, 3);
    addEdge(myGraph, 2, 3);

    // make reachable
    addEdge(myGraph, 3, 4);

    cout << (hasRoute(myGraph, 2, 4) ? "Route found" : "Route not found") << endl;

    return 0;
}

//    -->1--
// 0-|      |->3-->4
//    -->2--

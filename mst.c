/************************************************************************
 * Author: Patrick Spencer
 * Program: CS325 Final Project (Group 1)
 * Date: 6/6/18
 * Description: This file contains the specification for the functions required
 * to find a minimum spanning tree of the set of vertices from a traveling
 * salesman problem.
 * **********************************************************************/

#include "mst.h"

graph* findMST(matrix* weight) {
    // Create a new matrix were each row is a list of the vertices connected to an vertex
    // in sorted order by the weight of the edge that connects them.
    matrix* sortedWeights = malloc(sizeof(matrix));
    
    sortedWeights->size = weight->size;
    
    // allocated memory for sortedWeights
    sortedWeights->m = malloc(weight->size * sizeof(int*));
    int i, j, k;
    for(i = 0; i < weight->size; i++) {
        sortedWeights->m[i] = malloc(weight->size * sizeof(int));
    }
    
    for(i = 0; i < weight->size; i++) {
        sortWeights(weight->m[i], sortedWeights->m[i], weight->size);
    }
    
    for(i = 0; i < weight->size; i++) {
        for(j = 0; j < weight->size; j++) {
            printf("%d  ", sortedWeights->m[i][j]);
        }
        printf(" \n");
    }
    printf("\n\n");
    
    graph* g = createGraph(weight->size);
    
    
    // initialize list of vertices added and vertices not added
    adjList* added = malloc(sizeof(adjList));
    adjList* notAdded = malloc(sizeof(adjList));
    added->front = NULL;
    notAdded->front = NULL;
    
    //add all the vertices to notAdded
    for(i = 0; i < g->size; i++) {
        addAdjListNode(notAdded, i);
    }
    
    // find the edge with the smallest weight and add the two adjacent vertices to added
    int smallestA = sortedWeights->m[0][0];
    int smallestB = sortedWeights->m[0][1];
    
    for(i = 1; i < g->size; i++) {
        if(weight->m[i][sortedWeights->m[i][1]] < weight->m[smallestA][smallestB]) {
            smallestA = i;
            smallestB = sortedWeights->m[i][1];
        }
    }
    
    addAdjListNode(added, smallestA);
    addAdjListNode(added, smallestB);
    
    // remove the two vertices from not added
    removeAdjListNode(notAdded, smallestA);
    removeAdjListNode(notAdded, smallestB);
    
    // add this edge to the graph
    addEdge(g, smallestA, smallestB);
    
    // find the edge with the smallest weight that is connected to a vertex in added
    // add that edge to the graph and remove it's vertices from not added
    // continue adding edges until all of them are in added
    int smallestW;
    while(notAdded->front != NULL) {
        adjListNode* tmp = added->front;
        
        // initilize the vertices for the smallest edge weight
        if(tmp != NULL) {
            smallestW = 1000;
        }
        
        // find edge with smallest weight that is connected to the vertices in added and does not form a circuit
        while(tmp != NULL) {
            for(i = 1; i < g->size; i++) {
                if(weight->m[tmp->name][sortedWeights->m[tmp->name][i]] < smallestW) {
                    if(containsAdjListNode(added, sortedWeights->m[tmp->name][i]) != 1) {
                        smallestA = tmp->name;
                        smallestB = sortedWeights->m[tmp->name][i];
                        smallestW = weight->m[smallestA][smallestB];
                    }
                }
            }
            tmp = tmp->next;
        }
        
        // found the edge with the smallest weight add it to the graph
        addEdge(g, smallestA, smallestB);
        
        // add the new vertex to added and removed it from notAdded
        addAdjListNode(added, smallestB);
        removeAdjListNode(notAdded, smallestB);
    }
    
    
    return g;
}


void sortWeights(int* weightList, int* sortedList, int size) {
    int i, j;
    for(i = 0; i < size; i++) {
        sortedList[i] = i;
    }
    
    
    //using bubble sort for now so I can complete the mst algorithm.. I'll change it to merge sort later
    for(i = 0; i < size; i++) {
        for(j = 0; j < size - 1; j++) {
            if(weightList[sortedList[j]] > weightList[sortedList[j + 1]]) {
                int tmp = sortedList[j];
                sortedList[j] = sortedList[j + 1];
                sortedList[j + 1] = tmp;
            }
        }
    }
    
    
}
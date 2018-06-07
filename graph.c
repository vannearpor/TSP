/************************************************************************
 * Author: Patrick Spencer
 * Program: CS325 Final Project (Group 1)
 * Date: 6/6/18
 * Description: This file contains the specification for the graph
 * utility functions.
 * **********************************************************************/
 
#include "graph.h"
 
adjListNode* newAdjListNode(int name) {
    struct adjListNode* newNode = malloc(sizeof(adjListNode));
    newNode->name = name;
    newNode->next = NULL;
    return newNode;
}


graph* createGraph(int size) {
    int i;
    graph* g = malloc(sizeof(graph));
    g->size = size;
 
    // Create an array of adjacency lists.
    g->vertAry = malloc(size * sizeof(adjList*));
    for(i = 0; i < size; i++) {
        g->vertAry[i] = malloc(sizeof(adjList));
    }
 
    // Initialize each adjacency list as empty by 
    // making each front as NULL
    for (i = 0; i < size; ++i) {
        g->vertAry[i]->front = NULL;
    }
 
    return g;
}


void addEdge(graph* g, int vertA, int vertB) {
    // Add an edge from vertA to vertB.
    adjListNode* newNode = newAdjListNode(vertA);
    newNode->next = g->vertAry[vertB]->front;
    g->vertAry[vertB]->front = newNode;
 
    // Since graph is undirected, add an edge from
    // dest to src also
    newNode = newAdjListNode(vertB);
    newNode->next = g->vertAry[vertA]->front;
    g->vertAry[vertA]->front = newNode;
}


void addAdjListNode(adjList* list, int name){
    adjListNode* newNode = newAdjListNode(name);
    newNode->next = list->front;
    list->front = newNode;
}


void removeAdjListNode(adjList* list, int name) {
    adjListNode* tmp = list->front;
    //check is list is empty
    if(list->front != NULL) {
        
        //check first node in list
        if(list->front->name == name) {
            list->front = list->front->next;
            free(tmp);
        }
        
        //check rest of list
        else {
            adjListNode* tmp2 = tmp->next;
    
            while(tmp2 != NULL) {
                if(tmp2->name == name) {
                    tmp->next = tmp2->next;
                    free(tmp2);
                    break;
                }
                tmp = tmp2;
                tmp2 = tmp2->next;
            }
        }
    }
}

int containsAdjListNode(adjList* list, int name) {
    adjListNode* tmp = list->front;
    while(tmp != NULL) {
        if(tmp->name == name) {
            return 1;
        }
        tmp = tmp->next;
    }
    return 0;
}

void freeGraph(graph* g) {
    // to do
}

void printGraph(graph* g) {
    int i;
    adjListNode* tmp;
    for(i = 0; i < g->size; i++) {
        printf("Vertex %d:", i);
        
        tmp = g->vertAry[i]->front;
        while(tmp != NULL) {
            printf("-> %d", tmp->name);
            tmp = tmp->next;
        }
        printf("\n");
    }
}
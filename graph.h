/************************************************************************
 * Author: Patrick Spencer
 * Program: CS325 Final Project (Group 1)
 * Date: 6/6/18
 * Description: This file contains the definition for the graph struct and
 * its utility functions.
 * **********************************************************************/
 
#ifndef GRAPH_H
#define GRAPH_H

#include <stdlib.h>
#include <stdio.h>

typedef struct adjListNode {
    int name;
    struct adjListNode* next;
} adjListNode;

typedef struct adjList {
    adjListNode* front;
} adjList;

typedef struct graph {
    int size;
    adjList** vertAry;
} graph;

adjListNode* newAdjListNode(int name);
graph* createGraph(int size);
void addEdge(graph* g, int vertA, int vertB);
void addAdjListNode(adjList* list, int name);
void removeAdjListNode(adjList* list, int name);
int containsAdjListNode(adjList* list, int name);
void freeGraph(graph* g);
void printGraph(graph* g);

#endif
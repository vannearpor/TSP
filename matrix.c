/************************************************************************
 * Author: Patrick Spencer
 * Program: CS325 Final Project (Group 1)
 * Date: 6/6/18
 * Description: This file contains the specification for the getWeights
 * function which calculates the weights of all the edges in the traveling
 * salesman problem from a file and returns a matrix of the weights. It also
 * specifies the supporting function that calculates the weight of an edge
 * given the end points' coordinates.
 * **********************************************************************/
 
#include "matrix.h"

int** getWeights(char* filename) {
    // Open the file and check that it was successful
    FILE* infile = fopen(filename, "r");
    if (infile == NULL) {
        fprintf(stderr, "Failed to open %s.\n", filename);
        exit(1);
    }
    
    /********** Create a linked list of the vertices from the input file **********/
    char line[32]; // holds each line of input
    char* token; // for parsing each line into a vertex object
    int count; // number of vetices in the problem
    vertexList* frontSentinel = malloc(sizeof(vertexList)); // front of the linked list for storing vertices
    vertexList* tmp = frontSentinel; // temporary pointer for creating new vertex objects and adding them to the list
    tmp->v = NULL; // the front sentinel does not contain a vertex.
    tmp->next = NULL; // initialize the next pointer to null to prevent errors
    
    // read file and create a vertex for each line
    while(fgets(line, sizeof(line), infile)) {
        // increment count to find the total number of vertices in the problem
        count++;
        
        // parse line into a vertex object
        tmp->next = malloc(sizeof(vertexList)); // allocate memory for the next vertex
        tmp = tmp->next;
        tmp->v = malloc(sizeof(vertex));
        tmp->next = NULL;
        
        token = strtok(line, " \n"); // first number is the id of the vertex
        tmp->v->id = atoi(token);
        
        token = strtok(NULL, " \n"); // second number is the x-coordinate of the city
        tmp->v->xCoord = atoi(token);
        
        token = strtok(NULL, " \n"); // third number is the y-coordinate of the city
        tmp->v->yCoord = atoi(token);
    }
    
    /********** Create a Matrix of the weights with the list of vertices **********/
    // allocate memory for the matrix
    int** matrix = malloc(count * sizeof(int*));
    int i, 
    j, 
    weight;
    for(i = 0; i < count; i++) {
        matrix[i] = malloc(count * sizeof(int));
    }
    
    i = 0;
    tmp = frontSentinel->next;
    vertexList* tmp2;
    
    while(tmp != NULL) {
        tmp2 = tmp->next;
        j = i;
        matrix[i][j] = -1;
        while(tmp2 != NULL) {
            j++;
            weight = calcWeight(tmp->v, tmp2->v);
            matrix[i][j] = weight;
            matrix[j][i] = weight;
            tmp2 = tmp2->next;
        }
        i++;
        tmp = tmp->next;
    }
    
    // Free the data for the linked list
    
    
    return matrix;
}

int calcWeight(struct vertex* a, struct vertex* b) {
    double x = pow(a->xCoord - b->xCoord, 2);
    double y = pow(a->yCoord - b->yCoord, 2);
    return (int) (sqrt(x + y) + 0.5);
}

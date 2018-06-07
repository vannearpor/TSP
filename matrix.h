/************************************************************************
 * Author: Patrick Spencer
 * Program: CS325 Final Project (Group 1)
 * Date: 6/6/18
 * Description: This file contains the definition for the getWeights
 * function which calculates the weights of all the edges in the traveling
 * salesman problem from a file and returns a matrix of the weights. It also
 * defines the supporting function that calculates the weight of an edge
 * given the end points' coordinates.
 * **********************************************************************/
 
#ifndef MATRIX_H
#define MATRIX_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct matrix {
    int size;
    int** m;
} matrix;

typedef struct vertex {
    int id;
    int xCoord;
    int yCoord;
} vertex;

typedef struct vertexList {
    vertex* v;
    struct vertexList* next;
} vertexList;

matrix* getWeights(char* infile);
int calcWeight(vertex* a, vertex* b);

#endif
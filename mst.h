/************************************************************************
 * Author: Patrick Spencer
 * Program: CS325 Final Project (Group 1)
 * Date: 6/6/18
 * Description: This file contains the definition for the functions required
 * to find a minimum spanning tree of the set of vertices from a traveling
 * salesman problem.
 * **********************************************************************/
 
#ifndef MST_H
#define MST_H

#include "graph.h"
#include "matrix.h"

graph* findMST(matrix* weight);
void sortWeights(int* weightList, int* sortedList, int size);

#endif
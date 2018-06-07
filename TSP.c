//***********************************************
//Author: Michael, Patrick, Vannear
//Date: June 3, 2018
//Description: This program utilizes an algorithm to find an
// optimum solution for the travelling salesmen problem.
//***********************************************

#include "matrix.h"
#include "graph.h"
#include "mst.h"

int main(int argc, char* argv[]) {
    // check for correct number of command line arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s [input file name]\n", argv[0]);
        exit(1);
    }
    
    // create a matrix with the values for edge weights from the input file
    matrix* weight = getWeights(argv[1]);
    
    // find a Minimum Spanning Tree of the graph using the weights matrix
    graph* mst = findMST(weight);
    
    printGraph(mst);
}
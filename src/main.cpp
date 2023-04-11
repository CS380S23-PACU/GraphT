//***************************************************************************
// File name:  main.cpp
// Author:     
// Date:       
// Class:      CS380
// Assignment: Graphs
// Purpose:    Implement various graph algorithms
//***************************************************************************

#include <iostream>
#include <vector> 
#include <string>
#include <sstream>
#include <DirectedGraph.h>
#include <UndirectedGraph.h>
#include <queue>
#include <fstream>

//***************************************************************************
// Function:    main
//
// Description: Demonstrate use of the graph
//
// Parameters:  none
//
// Returned:    EXIT_SUCCESS
//***************************************************************************
int main(int argc, char* argv[])
{
//  DirectedGraph cGraph;
    UndirectedGraph cGraph;

  //std::ifstream inFile;

  //inFile.open(argv[1]);
  //inFile >> cGraph;

  cGraph.addEdge("x", "y", 1);
  cGraph.addEdge("y", "z", 2);
  cGraph.addEdge("x", "z", 20);
  cGraph.addEdge("x", "a", 1);
  cGraph.addEdge("a", "z", 2);
  cGraph.addEdge("x", "q", 4);
  cGraph.addEdge("a", "q", 4);
    
  cGraph.addEdge("q", "c", 1);
  cGraph.addEdge("z", "c", 4);
  cGraph.addEdge("c", "a", 14);
  cGraph.addEdge("y", "m", 4);
  cGraph.addEdge("m", "p", 4);
  cGraph.addEdge("p", "y", 4); 
    
  //cGraph.shortestPath("x");
  //cGraph.highlightPath("c");

  //cGraph.BFS("x");
  //cGraph.MST();

  std::cout << cGraph;

  return EXIT_SUCCESS;
}

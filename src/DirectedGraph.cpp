//***************************************************************************
// File name:  DirectedGraph.cpp
// Author:     chadd williams
// Date:       4/7/2023
// Class:      CS380
// Assignment: Graphs
// Purpose:    Implement various graph algorithms
//***************************************************************************

#include <DirectedGraph.h>

//***************************************************************************
// Constructor: DirectedGraph
//
// Description: Initialize the Graph
//
// Parameters:  None
//
//***************************************************************************
DirectedGraph::DirectedGraph()
{
}


//***************************************************************************
// Destructor:  ~DirectedGraph
//
// Description: Destory the Edges in the DirectedGraph
//
//***************************************************************************
DirectedGraph::~DirectedGraph()
{
}


//***************************************************************************
// Function:    addEdge
//
// Description: Add a directed edge to the graph, possibly adding nodes
//
// Parameters:  rcStart - start node label
//              rcEnd - end node label
//              weight - weight of edge
//
// Returned:    None
//***************************************************************************

void DirectedGraph::addEdge(const std::string& rcStart, 
const std::string & rcEnd, int weight)
{
  Node* pcStart, *pcEnd;

  pcStart = insertNode(rcStart);
  pcEnd = insertNode(rcEnd);

  Edge *pcEdge = new Edge(pcStart, pcEnd, weight);

  Graph::addEdge(pcStart, pcEnd, pcEdge);

}

//***************************************************************************
// Function:    getEdgeType
//
// Description: Get edge type suitable for Graphviz representation
//
// Parameters:  None
//
// Returned:    the string "->"
//***************************************************************************
std::string DirectedGraph::getEdgeType() const
{
  return "->";
}

//***************************************************************************
// Function:    graphType
//
// Description: Get Graph type suitable for Graphviz representation
//
// Parameters:  None
//
// Returned:    the string "diagraph"
//***************************************************************************
std::string DirectedGraph::graphType() const
{
  
  return "digraph";  
}

//***************************************************************************
// Function:    printEdge
//
// Description: Determine if this edge should be printed
//              Always true in a directed graph
//
// Parameters:  rcLeft - start node label
//              rcRight - end node label
//
// Returned:    true
//***************************************************************************
bool DirectedGraph::printEdge(const std::string &rcLeft, 
  const std::string&rcRight) const
{
  return true;
}

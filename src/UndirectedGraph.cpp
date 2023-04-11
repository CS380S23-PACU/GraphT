//***************************************************************************
// File name:  UndirectedGraph.cpp
// Author:     chadd williams
// Date:       4/7/2023
// Class:      CS380
// Assignment: Graphs
// Purpose:    Implement various graph algorithms
//***************************************************************************

#include <UndirectedGraph.h>

//***************************************************************************
// Constructor: UndirectedGraph
//
// Description: Initialize the Graph
//
// Parameters:  None
//
//***************************************************************************

UndirectedGraph::UndirectedGraph()
{
}


//***************************************************************************
// Destructor:  ~UndirectedGraph
//
// Description: Destory the Edges in the UndirectedGraph
//
//***************************************************************************
UndirectedGraph::~UndirectedGraph()
{
//  deallocateGraph();
}

//***************************************************************************
// Function:    deallocateGraph
//
// Description: Destory the edges and nodes in the graph
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void UndirectedGraph::deallocateGraph()
{
  auto cNodes = getNodes();

  for(auto node : cNodes)
  {
    for(auto end : getNeighbors(node))
    {
      if (node <= end)
      {
        deleteEdge(node->getLabel(), end->getLabel());
      }
    }
  }
  Graph::deallocateGraph();
}

//***************************************************************************
// Function:    addEdge
//
// Description: Add an UNdirected edge to the graph, possibly adding nodes
//              
//
// Parameters:  rcStart - start node label
//              rcEnd - end node label
//              weight - weight of edge
//
// Returned:    None
//***************************************************************************
void UndirectedGraph::addEdge(const std::string& rcStart, 
const std::string & rcEnd, int weight)
{
  Node* pcStart, *pcEnd;

  pcStart = insertNode(rcStart);
  pcEnd = insertNode(rcEnd);

  Edge *pcEdge = new Edge(pcStart, pcEnd, weight);

  Graph::addEdge(pcStart, pcEnd, pcEdge);
  Graph::addEdge(pcEnd, pcStart, pcEdge);

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
std::string UndirectedGraph::graphType() const
{
  return "graph";
}

//***************************************************************************
// Function:    getEdgeType
//
// Description: Get edge type suitable for Graphviz representation
//
// Parameters:  None
//
// Returned:    the string "--"
//***************************************************************************
std::string UndirectedGraph::getEdgeType() const
{
  return "--";
}

//***************************************************************************
// Function:    printEdge
//
// Description: Determine if this edge should be printed
//              In an undirected graph, only print edges
//              from lower -> high nodes
//
// Parameters:  rcLeft - start node label
//              rcRight - end node label
//
// Returned:    rcLeft <= rcRight
//***************************************************************************
bool UndirectedGraph::printEdge(const std::string &rcLeft, 
const std::string&rcRight) const
{
  return rcLeft <= rcRight;
}

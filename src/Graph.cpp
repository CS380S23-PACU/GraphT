//***************************************************************************
// File name:  Graph.cpp
// Author:     chadd williams
// Date:       4/7/2023
// Class:      CS380
// Assignment: Graphs
// Purpose:    Implement various graph algorithms
//***************************************************************************

#include <Graph.h>
#include <queue>
#include <set>
#include <algorithm>

//***************************************************************************
// Constructor: Graph
//
// Description: Initialize the Graph, colors
//
// Parameters:  None
//
//***************************************************************************
Graph::Graph()
{
  for ( auto value : {"blue", "crimson", "cyan",
     "deeppink", "goldenrod", "orangered"})
  {
    mcColors.push(value);
  }
}

//***************************************************************************
// Destructor:  ~Graph
//
// Description: 
//
//***************************************************************************
Graph::~Graph()
{

  deallocateGraph();
}

//***************************************************************************
// Function:    deallocateGraph
//
// Description: Destory the nodes in the graph
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void Graph::deallocateGraph()
{
  for(auto &left : mcAdjList)
  {
    for (auto &right : mcAdjList[left.first])
    {
      delete mcAdjList[left.first][right.first] ;
      mcAdjList[left.first][right.first] = nullptr;
    }
  }

  for(auto ptr : mcNodes)
  {
    delete ptr.second;
  }
  mcNodes.clear();
  mcAdjList.clear();
}

//***************************************************************************
// Function:    getNextColor
//
// Description: get the next color from the sequence
//
// Parameters:  None
//
// Returned:    the color
//***************************************************************************
std::string Graph::getNextColor()
{
  std::string nextColor;

  nextColor = mcColors.front();
  mcColors.pop();
  mcColors.push(nextColor);

  return nextColor;
}
    
//***************************************************************************
// Function:    getNodes
//
// Description: get all the nodes in the graph
//
// Parameters:  None
//
// Returned:    a vector of Node*
//***************************************************************************
std::vector<Node*> Graph::getNodes() const
{
  std::vector<Node*> cNodes;

  for(auto value : mcNodes)
  {
    cNodes.push_back(value.second);
  }
  return cNodes;
}
    
//***************************************************************************
// Function:    unhighlightEdges
//
// Description: set all edges to not highlighted
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void Graph::unhighlightEdges()
{
  for(auto ptr: mcAdjList)
  {
    for(auto edges:ptr.second)
    {
      edges.second->setHighlight(false);
    }
  }

}

//***************************************************************************
// Function:    addEdge
//
// Description: add an Edge to the graph
//
// Parameters:  pcStart - the start node
//              pcEnd   - the end node
//              pcEdge  - the edge
//
// Returned:    None
//***************************************************************************
void Graph::addEdge(const Node* pcStart, const Node *pcEnd, Edge *pcEdge)
{
  mcAdjList[pcStart->getLabel()][pcEnd->getLabel()]= pcEdge;
}

//***************************************************************************
// Function:    deleteEdge
//
// Description: delete an Edge from the graph
//
// Parameters:  rcStart - the start node label
//              rcEnd   - the end node label
//
// Returned:    None
//***************************************************************************
void Graph::deleteEdge(const std::string & rcStart, const std::string &rcEnd)
{
  delete mcAdjList[rcStart][rcEnd];
  mcAdjList[rcStart][rcEnd] = nullptr;
}

//***************************************************************************
// Function:    findEdge
//
// Description: Find an edge in the graph, return nullptr if not found
//
// Parameters:  pcStart - the start node
//              pcEnd   - the end node
//
// Returned:    Edge* - the pointer to the edge, nullptr otherwise
//***************************************************************************
Edge* Graph::findEdge(const Node* pcStart, const Node*  pcEnd) 
{
  Edge* pcRetVal = nullptr;

  if ( mcAdjList.find(pcStart->getLabel()) != mcAdjList.end())
  {
    if (mcAdjList[pcStart->getLabel()].find(pcEnd->getLabel()) 
      != mcAdjList[pcStart->getLabel()].end())
    {
      pcRetVal = mcAdjList[pcStart->getLabel()][pcEnd->getLabel()];
    }
  } 

  return pcRetVal;
}

//***************************************************************************
// Function:    getNeighbors
//
// Description: Get all the direct neighbors of a node
//
// Parameters:  pcNode - the  node
//
// Returned:    vector<Node*> - a vector of Node*
//***************************************************************************
std::vector<Node*> Graph::getNeighbors(const Node* pcNode) 
{
  std::vector<Node*> cRetVal;

  for(auto value : mcAdjList[pcNode->getLabel()])
  {
    cRetVal.push_back(value.second->getEnd());
  }
  return cRetVal;
}

//***************************************************************************
// Function:    getNode
//
// Description: Get the Node based on a string label
//
// Parameters:  rcLabel - the label
//
// Returned:    The node
//***************************************************************************
Node* Graph::getNode(const std::string &rcLabel) const
{
  return mcNodes.at(rcLabel);
}


//***************************************************************************
// Function:    insertNode
//
// Description: Insert a node into the graph. Ignore duplicate nodes
//
// Parameters:  rcLabel - the label
//
// Returned:    The node
//***************************************************************************
Node* Graph::insertNode(const std::string& rcLabel)
{
  if( mcNodes.find(rcLabel) == mcNodes.end() )
  {
    mcNodes.insert( {rcLabel, new Node(rcLabel)});
    mcAdjList.insert( {rcLabel, std::map<std::string, Edge*>()});
  }
  return mcNodes[rcLabel];
}

//***************************************************************************
// Function:    printGraph
//
// Description: Print the Graphviz representation of the graph to the screen
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void Graph::printGraph(std::ostream& rcOut)
{
  rcOut << graphType() << "{" << std::endl;
  for(auto &pair : mcAdjList)
  {
    for(auto &edge : pair.second)
    {
      if (printEdge(pair.first, edge.first))
      {
        rcOut << pair.first << " " << getEdgeType() << " ";
        rcOut << edge.first << " ";
        rcOut << mcAdjList[pair.first][edge.first]->printAttributes();
        rcOut << std::endl;
      }
    }
  }
  printNodes(rcOut);
  rcOut << "}" << std::endl;
}

//***************************************************************************
// Function:    printHighlightedEdges
//
// Description: Print the Graphviz representation of the graph to the screen
//              Print only the highlighted edges.
//
// Parameters:  rcOut - the stream to write to
//
// Returned:    None
//***************************************************************************
void Graph::printHighlightedEdges(std::ostream & rcOut)
{
  rcOut << graphType() << "{" << std::endl;

  for(auto &pair : mcAdjList)
  {
    for(auto &edge : pair.second)
    {
      if (printEdge(pair.first, edge.first) && 
      edge.second->isHighlighted () ) 
      {
        rcOut << pair.first << " " << getEdgeType() << " ";
        rcOut << edge.first << " ";
        rcOut << mcAdjList[pair.first][edge.first]->printAttributes();
        rcOut << std::endl;
      }
    }
  }
  printNodes(rcOut);
  rcOut << "}" << std::endl;
}

//***************************************************************************
// Function:    printPath
//
// Description: Print the Graphviz representation of the graph to the screen
//              Print only the path from rcDest back to the source via prev
//
// Parameters:  rcDest - the destination label
//              rcOut - the stream to write to
//
// Returned:    None
//***************************************************************************
void Graph::printPath(const std::string &rcDest, std::ostream& rcOut)
{
  Node *pcNode;
  Node* currNode = mcNodes[rcDest];

  rcOut << graphType() << "{" << std::endl;

  pcNode = currNode;
  while(pcNode->getPrev() != nullptr)
  {
 
    rcOut << pcNode->getPrev() << " " << getEdgeType() << " ";
    rcOut << currNode << " ";
    rcOut << mcAdjList[pcNode->getPrev()->getLabel()][currNode->getLabel()]->printAttributes();
    rcOut << std::endl;
    currNode = pcNode->getPrev();
    pcNode =  currNode;
  }
  printNodes(rcOut);
  rcOut << "}" << std::endl;
}

//***************************************************************************
// Function:    reset
//
// Description: reset each node and edge
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void Graph::reset()
{
   for(auto ptr : mcNodes)
  {
    ptr.second->reset();
  }

  for(auto ptr: mcAdjList)
  {
    for(auto edges:ptr.second)
    {
      edges.second->reset();
    }
  }
}

//***************************************************************************
// Function:    highlightPath
//
// Description: Highlight the edges on the path from dest back to the source
//              via prev using the given color
//
// Parameters:  rcDest - destination label
//              rcColor - color to use
//
// Returned:    None
//***************************************************************************
void Graph::highlightPath(const std::string &rcDest, 
const std::string &rcColor)
{
  Node *pcNode = mcNodes[rcDest];

  while (pcNode->getPrev() != nullptr )
  {
    mcAdjList[pcNode->getPrev()->getLabel()]
    [pcNode->getLabel()]->setOutputColor(rcColor);
    pcNode = pcNode->getPrev();
  }
}

//***************************************************************************
// Function:    printNodes
//
// Description: Print all the nodes in Graphviz representation to the screen
//
// Parameters:  rcOut - the stream to write to

//
// Returned:    None
//***************************************************************************
void Graph::printNodes(std::ostream &rcOut) const
{
  for(auto node : mcNodes)
  {
    rcOut << node.first;
    rcOut << "[color =\"";
    rcOut << node.second->getOutputColor();
    rcOut << "\"]";
    rcOut << std::endl;
  }
}

//***************************************************************************
// Function:    shortestPath
//
// Description: Run Dijkstra's algorithm from the source given as a parameter.
//              After this function completes, prev is set for each node.
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void Graph::shortestPath(const std::string &rcSource)
{
  auto cmp = [](auto left, auto right){
    return left->getDistance() > right->getDistance();};
  //PriorityQueue of Node*

}

//***************************************************************************
// Function:    BFS
//
// Description: Run BFS algorithm from the source given as a parameter.
//              Each edge in the BFS is highlighted with its color set to red
//
// Parameters:  None
//
// Returned:    A vector of Edges that represent the BFS
//***************************************************************************
std::vector<Edge*> Graph::BFS(const std::string &rcSource)
{
  std::vector<Edge*> result;
  std::queue<Node*> cQueue;
  return result;
}

//***************************************************************************
// Function:    DFS
//
// Description: Run DFS algorithm
//              Each root node in the DFS is highlighted with its own color
//              Each edge in a tree rooted at a node is the same color
//              as the root node.
//
// Parameters:  None
//
// Returned:    A vector of Nodes that represent the roots
//***************************************************************************
std::vector<Node*> Graph::DFS()
{
  std::queue<std::string> cQueue;
  std::vector<Node*> cRoots;

  return cRoots;
}

//***************************************************************************
// Function:    MST
//
// Description: Run Kruskal's algorithm
//              Each edge in the MST is highlighted with its color set to red              
//
// Parameters:  None
//
// Returned:    A vector of Edges that represent the MST
//***************************************************************************
std::vector<Edge*>  Graph::MST()
{
  std::vector<Edge*> cResult;
 
  auto cmp = [](auto left, auto right) {return !(*left < *right);};
  std::set<Edge*, decltype(cmp)> cEdgeSet;
  std::vector<std::set<Node*> *> cVecNodeSets;

 
  return cResult;
}


//***************************************************************************
// Function:    operator>>
//
// Description: Read the graph from a strea,           
//
// Parameters:  rcInFile : the stream to read from
//              rcGraph : the graph to read
//
// Returned:    The stream
//***************************************************************************
std::istream & operator>>(std::istream& rcInFile, Graph& rcGraph)
{
  rcGraph.deallocateGraph();
  rcGraph.read(rcInFile);
  return rcInFile;
}

//***************************************************************************
// Function:    read
//
// Description: Read the graph from a file. Virtual function to allow
//              subclasses to customize operator>>          
//
// Parameters:  rcInFile : the stream to read from
//              
// Returned:    None
//***************************************************************************
void Graph::read(std::istream& rcInFile)
{
  std::string left, right;
  int weight;

  while (rcInFile >> left >> right >> weight)
  {
    addEdge(left, right, weight);
  }
}


//***************************************************************************
// Function:    operator<<
//
// Description: Print the graph to a stream         
//
// Parameters:  rcInFile : the stream to read from
//              rcGraph : the graph to read
//
// Returned:    The stream
//***************************************************************************
std::ostream & operator<<(std::ostream& rcOut, Graph& rcGraph)
{
  rcGraph.printGraph(rcOut);
  return rcOut;
}

#include <Edge.h>
#include <Node.h>
#include <string>
#include <sstream>

const std::string Edge::ORIG_COLOR = "black";
int Edge::EDGE_CURR_ID = 0;

//***************************************************************************
// Constructor: Edge
//
// Description: Initialize the Edge, call reset()
//
// Parameters:  None
//
//***************************************************************************
Edge::Edge() : mID(EDGE_CURR_ID++)
{
  mWeight = 0;
  
  reset();
}

//***************************************************************************
// Constructor: Edge
//
// Description: Initialize the Edge with given nodes. call reset()
//
// Parameters:  pcStart - start node
//              pcEnd - end node
//              weight - weight
//
//***************************************************************************
Edge::Edge(Node *pcStart,Node* pcEnd,
  int weight)  : mID(EDGE_CURR_ID++)
{
  mpcNodeStart = pcStart;
  mpcNodeEnd = pcEnd;
  mWeight = weight;
  reset();
}

//***************************************************************************
// Destructor:  ~Edge
//
// Description: Destory the Edge
//
//***************************************************************************
Edge::~Edge()
{}

//***************************************************************************
// Function:    operator==
//
// Description: Compare the IDS of two Edges for equality
//
// Parameters:  rcOther - the Edge to compare against
//
// Returned:    true if equal, false otherwise
//***************************************************************************
bool Edge::operator==(const Edge &rcOther) const
{
  return mID == rcOther.mID;
}

//***************************************************************************
// Function:    operator<
//
// Description: Compare the IDS of two Edges for <
//
// Parameters:  rcOther - the Edge to compare against
//
// Returned:    true if <, false otherwise
//***************************************************************************
bool Edge::operator<(const Edge &rcOther) const
{
  return mID < rcOther.mID;
}

//***************************************************************************
// Function:    setOutputColor
//
// Description: set the output color (see Graphviz colors)
//
// Parameters:  rcOutputColor - the color
//
// Returned:    None
//***************************************************************************
void Edge::setOutputColor(const std::string &rcColor)
{
  mColor = rcColor;
}

//***************************************************************************
// Function:    getOutputColor
//
// Description: get the output color (see Graphviz colors)
//
// Parameters:  None
//
// Returned:    std::string - the color
//***************************************************************************
std::string Edge::getOutputColor() const
{
  return mColor;
}

//***************************************************************************
// Function:    getWeight
//
// Description: get the weight
//
// Parameters:  None
//
// Returned:    int - the weight
//***************************************************************************
int Edge::getWeight() const
{
  return mWeight;
}

//***************************************************************************
// Function:    setHighlight
//
// Description: set the highlight true or false
//
// Parameters:  bValue - the highlight value
//
// Returned:    None
//***************************************************************************
void Edge::setHighlight(bool bValue)
{
  mHighlight = bValue;
}

//***************************************************************************
// Function:    isHighlighted
//
// Description: Determine if the edge is highlighted
//
// Parameters:  None
//
// Returned:    true if highlighted, false otherwise
//***************************************************************************
bool Edge::isHighlighted() const
{
  return mHighlight;
}

//***************************************************************************
// Function:    printAttributes
//
// Description: Create Graphviz edge attributes
//
// Parameters:  None
//
// Returned:    std::string - string containing attributes
//***************************************************************************
std::string Edge::printAttributes() const
{
  std::stringstream ss;
  std::string data;

  ss << " [label=\""  << std::to_string(getWeight()) <<  "\" ";
    ss << " color = " << getOutputColor();
    ss << " ]" ;

  data = ss.str();
  return data;
}

//***************************************************************************
// Function:    reset
//
// Description: Unhighlight Edge and set color back to ORIG_COLOR
//
// Parameters:  None
//
// Returned:    NOne
//***************************************************************************
void Edge::reset()
{
  mHighlight = false;
  mColor = ORIG_COLOR;
}


//***************************************************************************
// Function:    getStart
//
// Description: Get the start node
//
// Parameters:  None
//
// Returned:    The start node
//***************************************************************************
Node* Edge::getStart() const
{
  return mpcNodeStart;
}

//***************************************************************************
// Function:    getEnd
//
// Description: Get the end node
//
// Parameters:  None
//
// Returned:    The end node
//***************************************************************************
Node* Edge::getEnd() const
{
  return mpcNodeEnd;
}
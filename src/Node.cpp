#include <Node.h>
#include <limits>

//***************************************************************************
// Constructor: Node
//
// Description: Initialize the Node, call reset()
//
// Parameters:  None
//
//***************************************************************************
Node::Node()
{
  reset();
}

//***************************************************************************
// Constructor: Node
//
// Description: Copy constructor
//
// Parameters:  rcOther - the node to copy
//
//***************************************************************************
Node::Node(const Node &rcOther)
{
  mLabel = rcOther.mLabel;
  mStart = rcOther.mStart;
  mFinish = rcOther.mFinish;
  mDistance = rcOther.mDistance;
  mPrevNode = nullptr;
  meColor = rcOther.meColor;
  mOutputColor = rcOther.mOutputColor;
  
}

//***************************************************************************
// Constructor: Node
//
// Description: Initialize the Node, call reset()
//
// Parameters:  rcLabel - the label for the Node
//
//***************************************************************************
Node::Node(const std::string &rcLabel) : mLabel(rcLabel)
{
  reset();
}

//***************************************************************************
// Destructor:  ~Node
//
// Description: Destory the node
//
//***************************************************************************
Node::~Node()
{
}

//***************************************************************************
// Function:    setPrev
//
// Description: Set the previous Node on a path
//
// Parameters:  rcPrev - the previous node
//
// Returned:    None
//***************************************************************************
void Node::setPrev(Node *rcPrev)
{
  mPrevNode = rcPrev;
}

//***************************************************************************
// Function:    getLabel
//
// Description: Get the label
//
// Parameters:  None
//
// Returned:    std::strin the label
//***************************************************************************
std::string Node::getLabel() const
{
  return mLabel;
}

//***************************************************************************
// Function:    getStart
//
// Description: Get the start time
//
// Parameters:  None
//
// Returned:    int - the start time
//***************************************************************************
int Node::getStart() const
{
  return mStart;
}

//***************************************************************************
// Function:    getFinish
//
// Description: Get the finish time
//
// Parameters:  None
//
// Returned:    int - the finish time
//***************************************************************************
int Node::getFinish() const
{
  return mFinish;
}

//***************************************************************************
// Function:    start
//
// Description: Set the start value
//
// Parameters:  startValue - the start value
//
// Returned:    None
//***************************************************************************
void Node::start(int startValue)
{
  mStart = startValue;
}

//***************************************************************************
// Function:    finish
//
// Description: Set the finish value
//
// Parameters:  finishValue - the finish value
//
// Returned:    None
//***************************************************************************
void Node::finish(int finValue)
{
  mFinish = finValue;
}

//***************************************************************************
// Function:    getPrev
//
// Description: Get the previous node on a path
//
// Parameters:  None
//
// Returned:    Node* - the previous node
//***************************************************************************
Node* Node::getPrev() const
{
  return mPrevNode;
}

//***************************************************************************
// Function:    operator==
//
// Description: Compare the labels of two nodes for equality
//
// Parameters:  rcRight - the node to compare against
//
// Returned:    true if equal, false otherwise
//***************************************************************************
bool Node::operator==(const Node &rcRight) const
{
  return mLabel == rcRight.mLabel;
}

//***************************************************************************
// Function:    operator==
//
// Description: Compare the labels of two nodes for equality
//
// Parameters:  rcLabel - the label to compare against
//
// Returned:    true if equal, false otherwise
//***************************************************************************
bool Node::operator==(const std::string &rcLabel) const
{
  return mLabel == rcLabel;
}

//***************************************************************************
// Function:    operator<<
//
// Description: Output the label to the stream
//
// Parameters:  rcOut - the stream
//              rcNode - the Node
//
// Returned:    the stream
//***************************************************************************
std::ostream &operator<<(std::ostream &rcOut, const Node &rcNode)
{

  rcOut << rcNode.getLabel();
  return rcOut;
}

//***************************************************************************
// Function:    isUnprocessed
//
// Description: Return if this Node is unprocessed (color == WHITE)
//
// Parameters:  None
//
// Returned:    true if unprocessed, false otherwise
//***************************************************************************
bool Node::isUnprocessed() const
{
  return meColor == Color::WHITE;
}


//***************************************************************************
// Function:    reset
//
// Description: Reset data: start, finish, prev, color, distance, outputcolor
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void Node::reset()
{
  mStart = -1;
  mFinish = -1;
  mPrevNode = nullptr;
  meColor = Color::WHITE;
  mDistance = std::numeric_limits<int>::max();
  mOutputColor = "black";
}

//***************************************************************************
// Function:    getDistance
//
// Description: get the distance
//
// Parameters:  None
//
// Returned:    int - the distance
//***************************************************************************
int Node::getDistance() const
{
  return mDistance;
}

//***************************************************************************
// Function:    setDistance
//
// Description: set the distance
//
// Parameters:  value - the distance
//
// Returned:    None
//***************************************************************************
void Node::setDistance(int value)
{
  mDistance = value;
}

//***************************************************************************
// Function:    operator<
//
// Description: Compare distances between two nodes
//
// Parameters:  rcRHS - the other node
//
// Returned:    turn if this < parameter, false otherwise
//***************************************************************************
bool Node::operator<(const Node& rcRHS) const
{
  return mDistance < rcRHS.mDistance;
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
void Node::setOutputColor(const std::string &rcOutputColor)
{
  mOutputColor = rcOutputColor;
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
std::string Node::getOutputColor() const
{
  return mOutputColor;
}

//***************************************************************************
// Function:    startProcessing
//
// Description: Set color to GRAY
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void Node::startProcessing()
{
  meColor = Color::GRAY;
}

//***************************************************************************
// Function:    finishProcessing
//
// Description: Set color to BLACK
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void Node::finishProcessing()
{
  meColor = Color::BLACK;
}
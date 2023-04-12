//***************************************************************************
// File name:  Edge.h
// Author:     chadd williams
// Date:       4/7/2023
// Class:      CS380
// Assignment: Graphs
// Purpose:    Implement various graph algorithms
//***************************************************************************
#pragma once

#include <memory>
#include <iostream>
#include <string>
#include <EdgeAttributes.h>

class Node;

class Edge
{

  public:

    Edge();
    Edge(Node*, Node*, int weight=0);
    ~Edge();

    Edge* newFlippedEdge() const;

    int getWeight() const;

    void setHighlight(bool);
    bool isHighlighted() const;

    void setOutputColor(const std::string &);
    std::string getOutputColor() const;

    std::string printAttributes() const;
    
    void reset();

    bool operator==(const Edge &) const;
    bool operator<(const Edge &) const;

    Node* getStart() const;
    Node* getEnd() const;
    

  private:

    std::shared_ptr<EdgeAttributes> mpsAttributes;

    Node* mpcNodeStart;
    Node* mpcNodeEnd;
    
    static const std::string ORIG_COLOR;

    const int mID;
    static int EDGE_CURR_ID;
};
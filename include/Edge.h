//***************************************************************************
// File name:  Edge.h
// Author:     chadd williams
// Date:       4/7/2023
// Class:      CS380
// Assignment: Graphs
// Purpose:    Implement various graph algorithms
//***************************************************************************
#pragma once

#include <iostream>
#include <string>

class Node;

class Edge
{

  public:

    Edge();
    Edge(Node*, Node*, int weight=0);
    ~Edge();

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

    int mWeight;
    bool mHighlight;
    std::string mColor;

    Node* mpcNodeStart;
    Node* mpcNodeEnd;
    
    static const std::string ORIG_COLOR;

    const int mID;
    static int EDGE_CURR_ID;
};
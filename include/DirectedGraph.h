//***************************************************************************
// File name:  DirectedGraph.h
// Author:     chadd williams
// Date:       4/7/2023
// Class:      CS380
// Assignment: Graphs
// Purpose:    Implement various graph algorithms
//***************************************************************************
#pragma once

#include <Graph.h>

class DirectedGraph : public Graph
{

  public:

    DirectedGraph();
    virtual ~DirectedGraph();
    virtual void addEdge(const std::string& , const std::string &, int = 1);

  protected:
    virtual std::string graphType() const;
    virtual std::string getEdgeType() const;
    virtual bool printEdge(const std::string &, const std::string&) const;
};
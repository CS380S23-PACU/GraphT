//***************************************************************************
// File name:  UndirectedGraph.h
// Author:     chadd williams
// Date:       4/7/2023
// Class:      CS380
// Assignment: Graphs
// Purpose:    Implement various graph algorithms
//***************************************************************************

#pragma once

#include <Graph.h>

class UndirectedGraph : public Graph
{

  public:

    UndirectedGraph();
    virtual ~UndirectedGraph();
    virtual void addEdge(const std::string& , const std::string &, int = 1);

 protected:
    virtual std::string graphType() const;
    virtual std::string getEdgeType() const;
    virtual bool printEdge(const std::string &, const std::string&) const;

};
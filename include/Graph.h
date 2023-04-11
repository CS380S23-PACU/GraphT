//***************************************************************************
// File name:  Graph.h
// Author:     chadd williams
// Date:       4/7/2023
// Class:      CS380
// Assignment: Graphs
// Purpose:    Implement various graph algorithms
//***************************************************************************

#pragma once

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <Node.h>
#include <Edge.h>
#include <queue>
//typedef std::pair<std::string, int> Edge;



class Graph
{
  public:
    Graph();
    virtual ~Graph();

    std::vector<Node*> getNodes() const;

    Edge* findEdge(const Node*, const Node*) ;

    std::vector<Node*> getNeighbors(const Node*) ;
    Node* getNode(const std::string &) const;

    void printGraph(std::ostream &);
    void printPath(const std::string &, std::ostream&);
    void printHighlightedEdges(std::ostream&);

    // unhighlight, set pred back to ""
    void reset();

    void highlightPath(const std::string &, 
    const std::string& rcColor = "red");

    void shortestPath(const std::string &rcSource);
    // then call highlightPath for dest node

    std::vector<Edge*> BFS(const std::string &rcSource);
    // then all printHighlightedEdges

    std::vector<Edge*> MST();
    // then all printHighlightedEdges

    std::vector<Node*> DFS();
    // change color for each root?
    // add color to edge for everything?
    // then: colorPath(dest, color)

    friend std::istream & operator>>(std::istream&, Graph&);

    virtual void read(std::istream&);

    friend std::ostream & operator<<(std::ostream&, Graph&);

    
  protected:

    void addEdge(const Node* , const Node*, Edge*);
    virtual void addEdge(const std::string& , const std::string &, int) = 0;
    void deleteEdge(const std::string& , const std::string &);
    virtual std::string graphType() const = 0;
    virtual std::string getEdgeType() const = 0;
    virtual bool printEdge(const std::string &, const std::string&) const = 0;
    Node* insertNode(const std::string&);
   
  private:
    std::map<std::string, Node*> mcNodes;
    std::map<std::string, std::map<std::string, Edge*>> mcAdjList;

   void unhighlightEdges();

    void printNodes(std::ostream &) const;
    std::queue<std::string> mcColors;

    std::string getNextColor();

};
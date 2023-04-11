//***************************************************************************
// File name:  Node.h
// Author:     chadd williams
// Date:       4/7/2023
// Class:      CS380
// Assignment: Graphs
// Purpose:    Implement various graph algorithms
//***************************************************************************
#pragma once


#include <iostream>
#include <string>

class Node 
{
  public:


    Node();
    Node(const std::string& label);
    Node(const Node &);
    ~Node();

    std::string getLabel() const;

    int getStart() const;
    int getFinish() const;

    int getDistance() const;
    void setDistance(int);

    void start(int);
    void finish(int);

    Node* getPrev() const;
    void setPrev(Node* );
    
    bool operator==(const Node &) const;
    bool operator==(const std::string &) const;
    bool operator<(const Node&) const;

    bool isUnprocessed() const;
    void startProcessing();
    void finishProcessing();

    
    void reset();

    friend std::ostream& operator<<(std::ostream&, const Node&);

    void setOutputColor(const std::string &);
    std::string getOutputColor() const;

  private:
    enum class Color {WHITE, GRAY, BLACK};

    std::string mLabel;
    int mStart;
    int mFinish;
    int mDistance;
    Node* mPrevNode;
    Color meColor;
    std::string mOutputColor;
};
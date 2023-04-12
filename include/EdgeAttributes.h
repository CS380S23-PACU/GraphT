//***************************************************************************
// File name:  EdgeAttributes.h
// Author:     chadd williams
// Date:       4/7/2023
// Class:      CS380
// Assignment: Graphs
// Purpose:    Implement various graph algorithms
//***************************************************************************

#pragma once
#include <string>


typedef struct EdgeAttributes
{
    int mWeight;
    bool mHighlight;
    std::string mColor;
} EdgeAttributes;
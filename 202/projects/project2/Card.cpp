#include "Card.h"

/*****************************************
 ** File:    Card.cpp
 ** Project: CMSC 202 Project 2, Spring 2017
 ** Author:  Daniel Diseroad
 ** Date:    3/5/17
 ** Section: 21
 ** E-mail:  ddiser1@umbc.edu
 **
 ** This file contains the Card class for Project 2.
 ** This program initializes a card for exploding kittens and
 ** includes several functions important to the Game and Player classes.
 **
 **
 ********************************************/

// Card
// Default constructor for Card class
Card::Card()
{
  m_type = 9;
  m_desc = "Invalid Card";
}

// Card
// Non-Default constructor for Card class, sets values for m_type and m_desc
Card::Card(int type, string desc)
{
  m_type = type;
  m_desc = desc;
}

// GetType
// Returns the type of card
int Card::GetType()
{
  return m_type;
}

// ToString
// Provides a string representation of the card, including type and description
string Card::ToString()
{
  //Switch statement denoting which type the card is based off of the member
  //variable "m_type"
  string output;
  switch(m_type)
    {
    case 0:
      output = "Bomb - ";
      break;
    case 1:
      output =  "Defuse - ";
      break;
    case 2:
      output = "Attack - ";
      break;
    case 3:
      output = "Skip - ";
      break;
    case 4:
      output = "Peek - ";
      break;
    case 5:
      output = "Shuffle - ";
      break;
    case 6:
    case 7:
    case 8:
    case 9:
      output = "Normal Card - ";
      break;
    default:
      output = "No type - ";
    }
  output += m_desc;
  return output;
}

#include "Player.h"

/*****************************************
 ** File:    Player.cpp
 ** Project: CMSC 202 Project 2, Spring 2017
 ** Author:  Daniel Diseroad
 ** Date:    3/5/17
 ** Section: 21
 ** E-mail:  ddiser1@umbc.edu
 **
 ** This file contains the Player class for project 2
 ** This program initializes a player for exploding kittens and
 ** includes several functions important to the Game class.
 **
 **
 ********************************************/

// Player
// Default constructor for player
Player::Player()
{
  vector<Card> hand;
  m_hand = hand;
  m_name = "Error";
  m_lost = false;
  m_extraTurn = false;
}

// Player
// Overloaded function, non-default function for player
Player::Player(string name)
{
  vector<Card> hand;
  m_hand = hand;
  m_name = name;
  m_lost = false;
  m_extraTurn = false;
}

// PlayCard
// Takes card from hand, removes it from vector and returns it
Card Player::PlayCard(int cardNum)
{
  Card playCard = m_hand.at(cardNum);
  m_hand.erase(m_hand.begin() + (cardNum));
  return playCard;
}

// LoseCard
// Steals card from hand, removes it from vector and returns it
Card Player::LoseCard(int cardNum)
{
  Card lostCard = m_hand.at(cardNum);
  m_hand.erase(m_hand.begin() + cardNum);
  return lostCard;
}

// HasCards
// Returns false if the player has no cards, true if the player has cards
bool Player::HasCards()
{
  if(static_cast<int>(m_hand.size()) == 0)
    return false;
  return true;
}

// HasLost
// Returns m_lost, which is true if the player has lost
bool Player::HasLost()
{
  return m_lost;
}

// HasExtraTurn
// Returns true if the player has an extra turn
bool Player::HasExtraTurn()
{
  return m_extraTurn;
}

// AddToHand
// Adds a card to a hand and returns an int that tells whether that card is a bomb card
int Player::AddToHand(Card newCard)
{
  m_hand.push_back(newCard);
  //If the card is an exploding kitten, return 0. Otherwise, return 1
  if(newCard.GetType() == 0)
    {
      cout << "You drew an exploding kitten: " << newCard.ToString() 
	   << endl;
      return 0;
    }
  return 1;
}

// GetName
// Returns the name of the player
string Player::GetName()
{
  return m_name;
}

// DisplayHand
// Prints out the cards in the player's hand
void Player::DisplayHand()
{
  for(int i = 0; i < static_cast<int>(m_hand.size()); i++)
    cout << i << " - " << m_hand.at(i).ToString() << endl;
}

// GetNumberOfCards
// Returns an int for the number of cards the player has in their hand
int Player::GetNumberOfCards()
{
  return static_cast<int>(m_hand.size());
}

// ReturnBomb
// Returns the bomb card in the user's hand
Card Player::ReturnBomb()
{
  Card bomb;
  for(int i = 0; i < static_cast<int>(m_hand.size()); i++)
    {
      if(m_hand.at(i).GetType()==0)
	bomb = m_hand.at(i);
    }
  return bomb;
}

// ReturnDefuse
// Returns the defuse card in the user's hand if there is one
Card Player::ReturnDefuse()
{
  Card defuse;
  for(int i = 0; i < static_cast<int>(m_hand.size()); i++)
    {
      if(m_hand.at(i).GetType()==1)
	{
	  defuse = m_hand.at(i);
	}
    }
  return defuse;
}

// HasPair
// Returns true if the player has a pair in their hand, false otherwise
bool Player::HasPair(int type)
{
  int counter = 0;
  for(int i = 0; i < static_cast<int>(m_hand.size());i++)
    {
      if(m_hand.at(i).GetType() == type)
	{
	  counter +=1;
	}
    }
  if(counter>1)
    return true;
  return false;
}

// SetLost
// Sets m_lost to passed boolean
void Player::SetLost(bool lost)
{
  m_lost = lost;
}

// SetExtraTurn
// Sets m_extraTurn to passed boolean
void Player::SetExtraTurn(bool extraTurn)
{
  m_extraTurn = extraTurn;
}

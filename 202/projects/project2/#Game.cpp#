#include "Game.h"
/*****************************************
 ** File:    Game.cpp
 ** Project: CMSC 202 Project 2, Spring 2017
 ** Author:  Daniel Diseroad
 ** Date:    3/5/17
 ** Section: 21
 ** E-mail:  ddiser1@umbc.edu 
 **
 ** This file contains the Game class for project 2
 ** This program initializes a game for exploding kittens and 
 ** runs the game and determines the winner.
 **
 **
 ********************************************/

// Game
// Starts the game
Game::Game()
{
  cout << "MEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOW\nWelcome to Exploding Kittens\n" 
       << "A Game By Elan Lee, Shane Small, and Matthew Inman\n"
       << "MEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOW\n\n";

  //starts the game here
  m_numPlayers = 0;
  //input validation
  while(m_numPlayers < 2 or m_numPlayers > 4)
    {
      cout << "How many players are playing?(2-4)" <<  endl;
      cin >> m_numPlayers;
    } 
  if(cin.peek()=='\n')
    cin.ignore();
  //makes players, loads in the deck and gives players cards
  SetNumPlayers(m_numPlayers);
  LoadDeck(DECK_NAME);
  AddBombCards(BOMB_NAME);
  PlayGame();
}

// SetNumPlayers
// Initializes Player objects for the number of players
void Game::SetNumPlayers(int numPlayers)
{
  string playerName = "";
  //makes player objects for each player
  for(int i = 0; i< m_numPlayers; i++)
    {
      cout << "\nName Player " << i+1 << endl;
      getline(cin,playerName);
      Player player = Player(playerName);
      m_players[i] = player;
    }  
}

// Shuffle
// Shuffles the cards in m_deck
void Game::Shuffle()
{
  Card temp;
  srand(RAND_SEED);
  int random,random2;
  int sizeDeck = static_cast<int>(m_deck.size());
  //swaps cards the same amount of times as the number of cards in the deck
  for(int i = 0; i < sizeDeck;i++)
    {
	random = rand() % sizeDeck;
	random2 = rand() % sizeDeck; 
	temp = m_deck.at(random);
	m_deck.at(random) = m_deck.at(random2);
	m_deck.at(random2) = temp;
    }
}

// Peek
// Shows the next CONST_NUM cards in m_deck
void Game::Peek()
{
  cout << "\n\nYou've peeked:" << endl;
  //finds the next CONST_NUM cards on the deck
  for(int i = 0; i < INIT_CARDS; i++)
    {
      cout << m_deck.at(i).ToString() << endl;
    }
}

// DrawCard
// Takes a card from the deck, removing it from m_deck and returning it
Card Game::DrawCard()
{
  Card drawnCard = m_deck.at(0);
  m_deck.erase(m_deck.begin());
  return drawnCard;
}

// HandleCard
// Does the appropriate action for the last card played
int Game::HandleCard(int playerNum)
{
  int lastIndexDiscard = static_cast<int>(m_discard.size())-1;
  Card disCard = m_discard.at(lastIndexDiscard);
  int type2 = -1;
  //find the 2nd to last card discarded
  if(lastIndexDiscard !=0)
    {
      Card disCard2 = m_discard.at(lastIndexDiscard-1);
      int type2 = disCard2.GetType();
    }
  int type = disCard.GetType();
  vector<int> validPlayers;
  int playerChoice = -1;
  Card stealCard,currentCard;
  //find valid players who haven't lost
  for(int i = 0;i < m_numPlayers; i++)
    {
      if(!m_players[i].HasLost())
	validPlayers.push_back(i);
    }
  Card defuse;
    switch(type)
      {
      //bomb card
      case 0:
	//checks to see if the player has a defusal card
	defuse = m_players[playerNum].ReturnDefuse();
	if(defuse.GetType() == 1)
	  {
	    cout << "\nPlay a defuse card or lose!\n" << endl;
	    m_players[playerNum].DisplayHand();
	    //validates that the index is actually in the hand
	    while(playerChoice < 0 or
		  playerChoice > m_players[playerNum].GetNumberOfCards()-1)
	      {
		cin >> playerChoice;
	        if(cin.peek()=='\n')
		  cin.ignore();
	      }
	    //defuse the bomb card and put it back in the deck.
	    if(defuse.ToString() == 
	       m_players[playerNum].LoseCard(playerChoice).ToString())
	      {
		cout << "The bomb has been defused!" << endl;
		m_deck.push_back(m_discard.at(lastIndexDiscard));
	      }
	    //explode the user, setting m_lost to true
	    else
	      {
		cout << "You exploded!" << endl;
		m_players[playerNum].SetLost(true);
	      }
	  }
	//explode the user, setting m_lost to true
	else
	  {
	    cout << "You exploded!" << endl;
	    m_players[playerNum].SetLost(true);
	  }
	playerNum -=1;
	break;

      case 1:
	break;

      //Give the next player an extra turn
      case 2:
	m_players[playerNum+1].SetExtraTurn(true);
	break;

      //Skip the next player's turn
      case 3:
	playerNum += 1;
	if(playerNum >= m_numPlayers)
	  playerNum = 0;
	cout << "Player " << playerNum+1 << " has been skipped!" << endl;
	break;

      //peek cards
      case 4:
	cout << endl;
	Peek();
	cout << endl;
	break;
       
      //shuffle cards
      case 5:
	Shuffle();
	cout << "\nThe cards have been shuffled" << endl;
	break;

      case 6:
      case 7:
      case 8:

      case 9:
	cout << "normal";
	//if the player has a pair, give them a chance to play it
	if(m_players[playerNum].HasPair(type))
	  playerNum -= 1;
	else if(type == type2)
	  {
	    int sizeValid = static_cast<int>(validPlayers.size());
	    bool valid = true;
	    cout << "You played a pair! You can now " << 
	      "steal a card from another player!" << endl;
	    //printing out the valid players to steal from
	    for(int i = 0; i < sizeValid;i++)
	      cout << i << "Player " << validPlayers.at(i) << endl;
	    //check user input
	    while(valid)
	      {
		cin >> playerChoice;
		if(cin.peek()=='\n')
		  cin.ignore();
		//Finds the possible valid players to steal from
		for(int i = 0; i < sizeValid; i++)
		  if(playerChoice == validPlayers.at(i))
		    valid = false;
	      }
	    //print out options for the user
	    for(int i; i < m_players[playerChoice].GetNumberOfCards();i++)
	      cout << "Card " << i << endl;
	    playerChoice = -1;
	    //check user input
	    while(playerChoice < 0 and 
		  playerChoice > m_players[playerChoice].GetNumberOfCards())
	      cin >> playerChoice;
	    //steal card chosen and put into the player's hand
	    currentCard = m_players[playerChoice].LoseCard(playerChoice);
	    m_players[playerNum].AddToHand(currentCard);
	  }
      }
    playerNum+=1;
  //if the number representing what player's turn it is is above the number of 
  //players, make it player 1's turn.
    if(playerNum >= m_numPlayers)
      playerNum = 0;
    return playerNum;
}

// PlayGame
// Actually runs the game, calling functions as needed
void Game::PlayGame()
{
  int playerNum = 0;
  int menuChoice,cardChoice,numLosers, winnerNum,explodingKit;
  Card currentCard;
  cout << "\n\nNumber of cards remaining: " << static_cast<int>(m_deck.size()) 
       << endl;
  while(true)
    {
      cardChoice = -1;
      menuChoice = 0;
      numLosers = 0;
      //if the player has an extra turn, make it so they have to go again
      for(int i = 0; i < m_numPlayers; i++)
        if(m_players[i].HasExtraTurn())
          {
	    if(playerNum != i)
	      {
		playerNum = i;
		m_players[i].SetExtraTurn(false);
	      }
          }
      //menu printout
      cout << endl << "It is player " << playerNum+1 << "'s turn" <<endl;
      cout << "What would you like to do:\n"  << endl;
      cout << "1. View Cards"  << endl;
      cout << "2. Play A Card"  << endl;
      cout << "3. Draw A Card"  << endl;
      //input validation
      while(menuChoice < 1 or menuChoice > 3)
	{
	  cin >> menuChoice;
	  if(cin.peek()=='\n')
	    cin.ignore();
	}
      //if the player has no cards, make them draw one
      if(!(m_players[playerNum].HasCards()))
	{
	  cout << "You have no cards, you must draw a card" << endl;
	  menuChoice = 3;
	}

      //switch statement for the menu choices: view, play, or draw
      switch(menuChoice)
	{
	  //view the hand
	case 1:
	  cout << endl;
	   m_players[playerNum].DisplayHand();
	  break;
	
	//play a card
	case 2:
	  cout << endl;
	  m_players[playerNum].DisplayHand();
	  cout << "\nSelect a card:" << endl;
	  if(cin.peek()=='\n')
	    cin.ignore();
	  //Input validation
	  while(cardChoice < 0 
		or cardChoice > m_players[playerNum].GetNumberOfCards()-1)
	    {
	      cin >> cardChoice;
	      if(cin.peek()=='\n')
		cin.ignore();
	    }
	  //Get the card that is going to be discarded and put it in the
	  //discard pile
	  currentCard = m_players[playerNum].PlayCard(cardChoice);
	  m_discard.push_back(currentCard);
	  cout << endl;
	  m_players[playerNum].DisplayHand();
	  //update the current player's turn and use the card
	  playerNum = HandleCard(playerNum);
	  break;

	case 3:
	  //if explodingKit equals 0, it is an exploding kitten
	  int explodingKit = m_players[playerNum].AddToHand(DrawCard());
	  m_players[playerNum].DisplayHand();
	  //check if the card is an exploding kitten and if so, put it in 
	  //the discard pile
	  if (explodingKit == 0)
	    {
	      //make the current card the bomb card and but it in the discard pile so 
	      //handle card can use it
	      currentCard = m_players[playerNum].PlayCard(m_players[playerNum]
							   .GetNumberOfCards()-1);
	      m_discard.push_back(currentCard);
	      //handle the exploding kitten
	      HandleCard(playerNum);
	    }
	  playerNum += 1;
	  break;
	}
      cout << endl << "Number of cards remaining: " << m_deck.size() << endl;
      //Checks to see if the game is over based on the number of losers 
      //and if so, who won
      for(int i=0;i < m_numPlayers;i++)
	{
	  if(m_players[i].HasLost())
	    numLosers++;
	  else
	    winnerNum = i;
	}
      //Prints out a congratulations to the player and exits the program
      if(numLosers == m_numPlayers-1)
	{
	  cout << "\n\nPlayer " << winnerNum+1 << " is the winner!!!" << endl;
	  exit(1);
	}
      //if the number representing what player's turn it is is above the number of
      //players, make it player 1's turn.
      if(playerNum >= m_numPlayers)
	playerNum = 0;
      //Finds out which player's turn it is based on which players have lost
      while(m_players[playerNum].HasLost())
	{
	  playerNum +=1;
	  cout << playerNum << endl;
	  if(playerNum >= m_numPlayers)
	    playerNum = 0;
	}
    }
}

// LoadDeck
// Loads the deck from a text file, making cards and putting them in m_deck
int Game::LoadDeck(string fileName)
{
  ifstream cardFile;
  cardFile.open(fileName.c_str());
  vector<int> types;
  vector<string> descriptions;
  string line;
  bool typeOrDesc = true;
  //make vectors from text file of the types and descriptions 
  while(getline(cardFile,line))
    {
      if(typeOrDesc)
	{
	  types.push_back(atoi(line.c_str()));
	  typeOrDesc = false;
	}
      else
	{
	  descriptions.push_back(line);
	  typeOrDesc = true;
	}
    }
  //make cards from the vectors
  for(int i = 0; i < static_cast<int>(types.size()); i++)
    {
      Card card = Card(types.at(i),descriptions.at(i));
      m_deck.push_back(card);
    }
  Shuffle();
  cout << "Shuffling the cards" << endl;
  //gives each player cards in their hand
  for(int i = 0; i < m_numPlayers; i++)
    {
      //gives the same number of cards as defined in const INIT_CARDS
      for(int j = 0; j < INIT_CARDS; j++)
	{
	  Card currentCard = m_deck.at(0);
	  m_players[i].AddToHand(currentCard);
	  m_deck.erase(m_deck.begin() + 0);
	}
    }
  cout << "cards handed out" << endl;
  cardFile.close();
  return 0;
} 

// AddBombCards
// Adds exploding kitten cards from a text file and shuffles m_deck
int Game::AddBombCards(string bombFile)
{
  ifstream cardFile;
  cardFile.open(bombFile.c_str());
  vector<int> types;
  vector<string> descriptions;
  string line;
  bool typeOrDesc = true;
  //make vectors from text file of the types and descriptions
  while(getline(cardFile,line))
    {
      if(typeOrDesc)
        {
          types.push_back(atoi(line.c_str()));
	  typeOrDesc = false;
        }
      else
        {
          descriptions.push_back(line);
	  typeOrDesc = true;
        }
    }
  //make cards from the two vectors
  for(int i = 0; i < types.size(); i++)
    {
      Card currentCard = Card(types.at(i),descriptions.at(i));
      m_deck.push_back(currentCard);
    }
  //shuffles the cards, including the exploding kittens
  Shuffle();
  cout << "Shuffling in the exploding kittens!" << endl;
  cardFile.close();
  return 0;
}
